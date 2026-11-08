
#include <iostream>
#include <limits>

#include "BST.h"
#include "FileManager.h"

using namespace std;

int main() {
    BST tree;
    int choice, value;
    string filename;

    do {
        cout << "\n===== MENU BST =====\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun element\n";
        cout << "3. Wyczysc drzewo\n";
        cout << "4. Szukaj elementu\n";
        cout << "5. Wyswietl drzewo\n";
        cout << "6. Preorder\n";
        cout << "7. Inorder\n";
        cout << "8. Postorder\n";
        cout << "9. Zapisz do pliku tekstowego\n";
        cout << "10. Zapisz do pliku binarnego\n";
        cout << "11. Wczytaj z pliku binarnego\n";
        cout << "12. Wczytaj z pliku tekstowego\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Podaj liczbe: ";
            cin >> value;
            tree.add(value);
            break;

        case 2:
            cout << "Podaj liczbe: ";
            cin >> value;
            tree.remove(value);
            break;

        case 3:
            tree.clearTree();
            break;

        case 4:
            cout << "Podaj liczbe: ";
            cin >> value;
            tree.searchPath(value);
            break;

        case 5:
            tree.displayTree();
            break;

        case 6:
            tree.displayPreorder();
            break;

        case 7:
            tree.displayInorder();
            break;

        case 8:
            tree.displayPostorder();
            break;

        case 9:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            tree.saveToTextFile(filename);
            break;

        case 10:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            tree.saveToBinaryFile(filename);
            break;

        case 11:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            tree.loadFromBinaryFile(filename);
            break;

        case 12:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            tree.loadFromValues(FileManager::readText(filename));
            break;

        case 0:
            cout << "Koniec programu.\n";
            break;

        default:
            cout << "Niepoprawny wybor!\n";
        }

    } while (choice != 0);

    return 0;
}
