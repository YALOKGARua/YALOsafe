#include "storage.h"
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <iterator>

Storage::Storage(char encryptionKey)
    : encryptionKey(encryptionKey), encryptionModule(encryptionKey) {}

void Storage::save(const std::string& key, const std::string& data) {
    std::string encryptedData = encryptionModule.encrypt(data, encryptionKey);
    std::string fileName = generateFileName(key);
    std::ofstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        file.write(encryptedData.c_str(), encryptedData.size());
        file.close();
    }
    else {
        throw std::runtime_error("Unable to open file for writing");
    }
}

std::string Storage::load(const std::string& key) const {
    std::string fileName = generateFileName(key);
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        std::string encryptedData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return encryptionModule.decrypt(encryptedData, encryptionKey);
    }
    else {
        throw std::runtime_error("Unable to open file for reading");
    }
}

void Storage::remove(const std::string& key) {
    std::string fileName = generateFileName(key);
    if (std::filesystem::remove(fileName)) {
    }
    else {
        throw std::runtime_error("Unable to delete file");
    }
}

std::vector<std::string> Storage::listKeys() const {
    std::vector<std::string> keys;
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::string fileName = entry.path().filename().string();
        if (fileName.length() > 4 && fileName.compare(fileName.length() - 4, 4, ".dat") == 0) {
            keys.push_back(fileName.substr(0, fileName.size() - 4));
        }
    }
    return keys;
}

std::string Storage::generateFileName(const std::string& key) const {
    return key + ".dat";
}
