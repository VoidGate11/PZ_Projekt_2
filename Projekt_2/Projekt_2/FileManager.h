/**
 * @file FileManager.h
 * @brief Deklaracja klasy do obslugi plikow tekstowych.
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

 /**
  * @brief Klasa odpowiedzialna za zapis i odczyt danych z plikow.
  */
class FileManager {
public:
    /**
     * @brief Zapisuje liczby do pliku tekstowego.
     * @param filename Nazwa pliku.
     * @param values Wektor liczb.
     */
    static void saveText(const std::string& filename,
        const std::vector<int>& values);

    /**
     * @brief Odczytuje liczby z pliku tekstowego.
     * @param filename Nazwa pliku.
     * @return Wektor odczytanych liczb.
     */
    static std::vector<int> readText(const std::string& filename);
};

#endif