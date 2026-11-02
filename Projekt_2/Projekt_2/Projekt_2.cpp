
#include <iostream>
#include <limits>

#include "BST.h"
#include "FileManager.h"

using namespace std;

int main() {

    BST tree;

    int choice;
    int value;

    string filename;

    do {
        cout << "\n========== DRZEWO BST ==========\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun element\n";
        cout << "3. Usun cale drzewo\n";
        cout << "4. Szukaj drogi do elementu\n";
        cout << "5. Wyswietl drzewo graficznie\n";
        cout << "6. Preorder\n";
        cout << "7. Inorder\n";
        cout << "8. Postorder\n";
        cout << "9. Zapisz drzewo do pliku tekstowego\n";
        cout << "10. Zapisz drzewo do pliku binarnego\n";
        cout << "11. Wczytaj drzewo z pliku binarnego\n";
        cout << "12. Wczytaj liczby z pliku tekstowego\n";
        cout << "0. Wyjscie\n";
        cout << "================================\n";

        cout << "Wybierz opcje: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Niepoprawna opcja!\n";
            continue;
        }

        switch (choice) {

        case 1:
            cout << "Podaj liczbe: ";
            if (cin >> value)
                tree.add(value);
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Niepoprawne dane!\n";
            }
            break;

        case 2:
            cout << "Podaj liczbe do usuniecia: ";
            if (cin >> value)
                tree.remove(value);
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Niepoprawne dane!\n";
            }
            break;

        case 3:
            tree.clearTree();
            break;

        case 4:
            cout << "Podaj szukana liczbe: ";
            if (cin >> value)
                tree.searchPath(value);
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Niepoprawne dane!\n";
            }
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

        case 12: {
            cout << "Podaj nazwe pliku: ";
            cin >> filename;

            vector<int> values =
                FileManager::readText(filename);

            tree.loadFromValues(values);
            break;
        }

        case 0:
            cout << "Zamykanie programu...\n";
            break;

        default:
            cout << "Nie ma takiej opcji!\n";
        }

    } while (choice != 0);

    return 0;
}
