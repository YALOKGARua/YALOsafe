#include "storage.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>

namespace fs = std::filesystem;

bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() >= suffix.length()) {
        return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
    }
    return false;
}

Storage::Storage(char someParameter) : encryptionModule("someKey") {
    storagePath = "storage_directory";
}

std::string Storage::generateFileName(const std::string& key) const {
    return storagePath + "/" + key + ".dat";
}

std::vector<std::string> Storage::listKeys() const {
    std::vector<std::string> keys;
    try {
        for (const auto& entry : fs::directory_iterator(storagePath)) {
            if (endsWith(entry.path().string(), ".dat")) {
                keys.push_back(entry.path().stem().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "List files error: " << e.what() << '\n';
    }
    return keys;
}

void Storage::remove(const std::string& key) {
    std::string filePath = generateFileName(key);
    try {
        if (fs::exists(filePath)) {
            fs::remove(filePath);
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Delete error: " << e.what() << '\n';
    }
}

std::string Storage::load(const std::string& key) const {
    std::string filePath = generateFileName(key);
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << '\n';
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    return content;
}

void Storage::save(const std::string& key, const std::string& data) {
    std::string filePath = generateFileName(key);
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << '\n';
        return;
    }
    file << data;
}
