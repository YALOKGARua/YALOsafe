#include "backup.h"
#include <filesystem>
#include <iostream>

void createBackup(const std::string& filePath) {
    std::string backupPath = filePath + ".bak";
    try {
        std::filesystem::copy_file(filePath, backupPath, std::filesystem::copy_options::overwrite_existing);
        std::cout << "Backup created successfully: " << backupPath << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error creating backup: " << e.what() << std::endl;
    }
}
