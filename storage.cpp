#include "storage.h"
#include <fstream>
#include <sstream>

std::string Storage::generateFileName(const std::string& key) const {
    return key + ".dat";
}

void Storage::save(const std::string& key, const std::string& data) {
    std::ofstream file(generateFileName(key), std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing: " + generateFileName(key));
    }
    file.write(data.c_str(), data.size());
    if (!file) {
        throw std::runtime_error("Failed to write data to file: " + generateFileName(key));
    }
}

std::string Storage::load(const std::string& key) const {
    std::ifstream file(generateFileName(key), std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading: " + generateFileName(key));
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    if (!file) {
        throw std::runtime_error("Failed to read data from file: " + generateFileName(key));
    }
    return buffer.str();
}
