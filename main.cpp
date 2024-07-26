#include <iostream>
#include "storage.h"
#include "logger.h"
#include "backup.h"

void printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Save data" << std::endl;
    std::cout << "2. Load data" << std::endl;
    std::cout << "3. Delete data" << std::endl;
    std::cout << "4. List all keys" << std::endl;
    std::cout << "5. Create backup" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    char encryptionKey = 'K';
    Storage storage(encryptionKey);
    Logger logger("events.log");

    int choice;
    std::string key;
    std::string data;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cin.ignore();
            std::cout << "Enter data: ";
            std::getline(std::cin, data);

            try {
                storage.save(key, data);
                logger.log("Data saved with key: " + key);
                std::cout << "Data saved successfully." << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        case 2:
            std::cout << "Enter key: ";
            std::cin >> key;

            try {
                data = storage.load(key);
                logger.log("Data loaded with key: " + key);
                std::cout << "Loaded Data: " << data << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        case 3:
            std::cout << "Enter key: ";
            std::cin >> key;

            try {
                storage.remove(key);
                logger.log("Data deleted with key: " + key);
                std::cout << "Data deleted successfully." << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        case 4:
            try {
                std::vector<std::string> keys = storage.listKeys();
                std::cout << "Stored Keys:" << std::endl;
                for (const std::string& k : keys) {
                    std::cout << "- " << k << std::endl;
                }
                logger.log("Listed all keys");
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        case 5:
            std::cout << "Enter key for backup: ";
            std::cin >> key;

            try {
                std::string filePath = storage.generateFileName(key);
                createBackup(filePath);
                logger.log("Backup created for key: " + key);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        case 6:
            std::cout << "Exiting..." << std::endl;
            logger.log("Program exited");
            return 0;

        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
