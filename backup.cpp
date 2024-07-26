#include "backup.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void Backup::createBackup(const std::string& filePath) {
    std::string backupPath = filePath + ".bak";
    try {
        fs::copy_file(filePath, backupPath, fs::copy_options::overwrite_existing);
        std::cout << "Backup created at: " << backupPath << '\n';
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Backup error: " << e.what() << '\n';
    }
}

void Backup::restoreBackup(const std::string& backupPath, const std::string& destinationPath) {
    try {
        fs::copy_file(backupPath, destinationPath, fs::copy_options::overwrite_existing);
        std::cout << "Backup restored from: " << backupPath << " to: " << destinationPath << '\n';
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Restore error: " << e.what() << '\n';
    }
}
