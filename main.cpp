#include <iostream>
#include "storage.h"

int main() {
    Storage storage;

    std::string key = "Yalokpass";
    std::string data = "Test data.";

    try {
        storage.save(key, data);
        std::string loadedData = storage.load(key);

        std::cout << "Original Data: " << data << std::endl;
        std::cout << "Loaded Data: " << loadedData << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
