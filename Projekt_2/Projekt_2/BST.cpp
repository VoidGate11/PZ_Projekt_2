
#include "BST.h"

#include <iostream>
#include <fstream>
#include <algorithm>

/**
 * @file BST.cpp
 * @brief Implementacja metod klasy BST.
 */

using namespace std;

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    clearTree();
}

// Dodawanie elementu
void BST::add(int value) {
    Node** current = &root;

    while (*current != nullptr) {
        if (value < (*current)->value)
            current = &((*current)->left);
        else if (value > (*current)->value)
            current = &((*current)->right);
        else {
            cout << "Element juz istnieje!\n";
            return;
        }
    }

    *current = new Node(value);

    cout << "Dodano element: " << value << endl;
}

// Wyszukiwanie najmniejszego elementu
Node* BST::findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;

    return node;
}

// Usuwanie elementu
Node* BST::remove(Node* node, int value) {
    if (node == nullptr)
        return nullptr;

    if (value < node->value) {
        node->left = remove(node->left, value);
    }
    else if (value > node->value) {
        node->right = remove(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }

    return node;
}

void BST::remove(int value) {
    if (search(root, value) == nullptr) {
        cout << "Nie znaleziono elementu.\n";
        return;
    }

    root = remove(root, value);
    cout << "Usunieto element: " << value << endl;
}

// Wyszukiwanie elementu
Node* BST::search(Node* node, int value) {
    if (node == nullptr || node->value == value)
        return node;

    if (value < node->value)
        return search(node->left, value);

    return search(node->right, value);
}

// Wyszukiwanie drogi do elementu
bool BST::searchPath(int value) {
    Node* current = root;

    cout << "Droga: ";

    while (current != nullptr) {
        cout << current->value;

        if (current->value == value) {
            cout << "\nZnaleziono element!\n";
            return true;
        }

        cout << " -> ";

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    cout << "\nNie znaleziono elementu!\n";
    return false;
}

// Usuwanie całego drzewa
void BST::clear(Node* node) {
    if (node == nullptr)
        return;

    clear(node->left);
    clear(node->right);

    delete node;
}

void BST::clearTree() {
    clear(root);
    root = nullptr;

    cout << "Drzewo zostalo wyczyszczone.\n";
}

// PREORDER
void BST::preorder(Node* node) {
    if (node == nullptr)
        return;

    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::displayPreorder() {
    cout << "PREORDER: ";
    preorder(root);
    cout << endl;
}

// INORDER
void BST::inorder(Node* node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void BST::displayInorder() {
    cout << "INORDER: ";
    inorder(root);
    cout << endl;
}

// POSTORDER
void BST::postorder(Node* node) {
    if (node == nullptr)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void BST::displayPostorder() {
    cout << "POSTORDER: ";
    postorder(root);
    cout << endl;
}

// Graficzne wyświetlanie drzewa
void BST::printTree(Node* node, int space) {
    if (node == nullptr)
        return;

    space += 5;

    printTree(node->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << node->value << endl;

    printTree(node->left, space);
}

void BST::displayTree() {
    if (root == nullptr) {
        cout << "Drzewo jest puste.\n";
        return;
    }

    printTree(root, 0);
}

// Zapis drzewa do pliku tekstowego
void BST::saveText(Node* node, string& output) {
    if (node == nullptr)
        return;

    output += to_string(node->value) + "\n";

    saveText(node->left, output);
    saveText(node->right, output);
}

void BST::saveToTextFile(const string& filename) {
    ofstream file(filename);

    if (!file) {
        cout << "Blad otwierania pliku!\n";
        return;
    }

    string output;
    saveText(root, output);

    file << output;

    file.close();

    cout << "Zapisano drzewo do pliku tekstowego.\n";
}

// Wczytywanie liczb do drzewa
void BST::loadFromValues(const vector<int>& values) {
    for (int value : values)
        add(value);

    cout << "Wczytywanie zakonczone.\n";
}

// Zapis binarny
void BST::saveBinary(vector<int>& values, Node* node) {
    if (node == nullptr)
        return;

    values.push_back(node->value);

    saveBinary(values, node->left);
    saveBinary(values, node->right);
}

void BST::saveToBinaryFile(const string& filename) {
    ofstream file(filename, ios::binary);

    if (!file) {
        cout << "Blad otwierania pliku!\n";
        return;
    }

    vector<int> values;
    saveBinary(values, root);

    size_t size = values.size();

    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    if (!values.empty()) {
        file.write(
            reinterpret_cast<const char*>(values.data()),
            values.size() * sizeof(int)
        );
    }

    file.close();

    cout << "Zapisano drzewo binarnie.\n";
}

// Odczyt binarny
void BST::loadFromBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "Blad otwierania pliku!\n";
        return;
    }

    size_t size;

    if (!file.read(reinterpret_cast<char*>(&size), sizeof(size))) {
        cout << "Niepoprawny plik!\n";
        return;
    }

    // Ochrona przed nieprawidlowym rozmiarem
    if (size > 1000000 ||
        size > static_cast<size_t>(
            numeric_limits<streamsize>::max() / sizeof(int))) {
        cout << "Niepoprawny rozmiar danych!\n";
        return;
    }

    vector<int> values(size);

    if (size > 0) {
        if (!file.read(
            reinterpret_cast<char*>(values.data()),
            static_cast<streamsize>(size * sizeof(int)))) {
            cout << "Blad odczytu danych!\n";
            return;
        }
    }

    if (file.peek() != EOF) {
        cout << "Plik zawiera dodatkowe dane!\n";
        return;
    }

    clearTree();

    for (int value : values)
        add(value);

    cout << "Odczytano drzewo z pliku binarnego.\n";
}
