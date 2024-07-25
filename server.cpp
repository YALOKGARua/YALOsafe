#include "server.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Server::start() {
    std::cout << "Server started. Listening for requests..." << std::endl;
    handleRequest();
}

void Server::handleRequest() {
    std::string key = "Yalokpass";
    std::string data = "Test data.";

    saveData(key, data);
    std::string loadedData = loadData(key);

    std::cout << "Loaded Data: " << loadedData << std::endl;
}

void Server::saveData(const std::string& key, const std::string& data) {
    std::ofstream file(key + ".dat", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file for writing: " + key + ".dat" << std::endl;
        return;
    }
    file.write(data.c_str(), data.size());
}

std::string Server::loadData(const std::string& key) const {
    std::ifstream file(key + ".dat", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file for reading: " + key + ".dat" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
