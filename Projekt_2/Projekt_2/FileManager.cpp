
#include "FileManager.h"

#include <iostream>
#include <fstream>

using namespace std;

void FileManager::saveText(
    const string& filename,
    const vector<int>& values) {

    ofstream file(filename);

    if (!file) {
        cout << "Nie mozna utworzyc pliku!\n";
        return;
    }

    for (int value : values)
        file << value << endl;

    cout << "Zapisano dane do pliku tekstowego.\n";
}

vector<int> FileManager::readText(const string& filename) {
    vector<int> values;

    ifstream file(filename);

    if (!file) {
        cout << "Nie mozna otworzyc pliku!\n";
        return values;
    }

    int number;

    while (file >> number)
        values.push_back(number);

    if (!file.eof()) {
        cout << "Blad: plik zawiera niepoprawne dane.\n";
        values.clear();
    }

    cout << "Wczytano " << values.size()
         << " liczb.\n";

    return values;
}
