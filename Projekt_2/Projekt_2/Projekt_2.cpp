
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

}
