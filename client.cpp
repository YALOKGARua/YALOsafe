#include "client.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Client::sendRequest(const std::string& key, const std::string& data) {
    std::ofstream file(key + ".dat", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file for writing: " + key + ".dat" << std::endl;
        return;
    }
    file.write(data.c_str(), data.size());
}

std::string Client::fetchData(const std::string& key) {
    std::ifstream file(key + ".dat", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file for reading: " + key + ".dat" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
