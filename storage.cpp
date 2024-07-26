#include "storage.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

Storage::Storage(char someParameter) : parameter(someParameter) {}

std::string Storage::generateFileName(const std::string& key) const {
    return key + ".txt";
}

std::vector<std::string> Storage::listKeys() const {
    std::vector<std::string> keys;
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".txt") {
            std::string fileName = entry.path().stem().string();
            keys.push_back(fileName);
        }
    }
    return keys;
}

void Storage::remove(const std::string& key) {
    std::string fileName = generateFileName(key);
    if (fs::exists(fileName)) {
        fs::remove(fileName);
        std::cout << "Removed key: " << key << '\n';
    }
    else {
        std::cerr << "File does not exist: " << fileName << '\n';
    }
}

std::string Storage::load(const std::string& key) const {
    std::string fileName = generateFileName(key);
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "File not found: " << fileName << '\n';
        return "";
    }
    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return data;
}

void Storage::save(const std::string& key, const std::string& data) {
    std::string fileName = generateFileName(key);
    std::ofstream file(fileName);
    if (file) {
        file << data;
        std::cout << "Saved data for key: " << key << '\n';
    }
    else {
        std::cerr << "Error saving file: " << fileName << '\n';
    }
}
