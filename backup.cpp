#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void createBackup(const std::string& filePath) {
    std::string backupPath = filePath + ".bak";
    try {
        fs::copy_file(filePath, backupPath, fs::copy_options::overwrite_existing);
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Backup error: " << e.what() << '\n';
    }
}
