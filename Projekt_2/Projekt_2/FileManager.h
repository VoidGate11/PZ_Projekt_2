
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager {
public:
    static void saveText(const std::string& filename,
                         const std::vector<int>& values);

    static std::vector<int> readText(const std::string& filename);
};

#endif
