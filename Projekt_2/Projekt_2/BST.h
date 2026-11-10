/**
 * @file BST.h
 * @brief Deklaracja klasy drzewa BST.
 */

#ifndef BST_H
#define BST_H

#include "Node.h"
#include <vector>
#include <string>

 /**
  * @brief Klasa implementujaca drzewo binarnych poszukiwan.
  */
class BST {
private:
    Node* root;

    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    Node* search(Node* node, int value);
    void clear(Node* node);

    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);

    void printTree(Node* node, int space);
    void saveText(Node* node, std::string& output);
    void saveBinary(std::vector<int>& values, Node* node);

public:
    /** @brief Konstruktor drzewa BST. */
    BST();

    /** @brief Destruktor zwalnia pamiec drzewa. */
    ~BST();

    /**
     * @brief Dodaje element do drzewa.
     * @param value Wartosc do dodania.
     */
    void add(int value);

    /**
     * @brief Usuwa element z drzewa.
     * @param value Wartosc do usuniecia.
     */
    void remove(int value);

    /** @brief Usuwa wszystkie elementy drzewa. */
    void clearTree();

    /**
     * @brief Wyszukuje element i wyswietla droge do niego.
     * @param value Poszukiwana wartosc.
     * @return true Jesli znaleziono element, false w przeciwnym razie.
     */
    bool searchPath(int value);

    /** @brief Wyswietla drzewo w kolejnosci preorder. */
    void displayPreorder();

    /** @brief Wyswietla drzewo w kolejnosci inorder. */
    void displayInorder();

    /** @brief Wyswietla drzewo w kolejnosci postorder. */
    void displayPostorder();

    /** @brief Wyswietla drzewo w postaci graficznej. */
    void displayTree();

    /**
     * @brief Zapisuje drzewo do pliku tekstowego.
     * @param filename Nazwa pliku.
     */
    void saveToTextFile(const std::string& filename);

    /**
     * @brief Wczytuje wartosci do drzewa.
     * @param values Wektor wartosci.
     */
    void loadFromValues(const std::vector<int>& values);

    /**
     * @brief Zapisuje drzewo do pliku binarnego.
     * @param filename Nazwa pliku.
     */
    void saveToBinaryFile(const std::string& filename);

    /**
     * @brief Wczytuje drzewo z pliku binarnego.
     * @param filename Nazwa pliku.
     */
    void loadFromBinaryFile(const std::string& filename);
};

#endif