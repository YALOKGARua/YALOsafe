#include "menu.h"
#include <iostream>
#include "backup.h"
#include "storage.h"

void Menu::display() {
    std::cout << "1. Create Backup\n";
    std::cout << "2. Restore Backup\n";
    std::cout << "3. Save Data\n";
    std::cout << "4. Load Data\n";
    std::cout << "5. List Keys\n";
    std::cout << "6. Remove Key\n";
    std::cout << "7. Exit\n";
}

void Menu::handleInput() {
    Backup backupManager;
    Storage storageManager('A'); // Example parameter
    int choice;
    std::string filePath, backupPath, restorePath, key, data;

    while (true) {
        display();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore leftover newline character

        switch (choice) {
        case 1:
            std::cout << "Enter file path to backup: ";
            std::getline(std::cin, filePath);
            backupManager.createBackup(filePath);
            break;

        case 2:
            std::cout << "Enter backup file path: ";
            std::getline(std::cin, backupPath);
            std::cout << "Enter destination path: ";
            std::getline(std::cin, restorePath);
            backupManager.restoreBackup(backupPath, restorePath);
            break;

        case 3:
            std::cout << "Enter key: ";
            std::getline(std::cin, key);
            std::cout << "Enter data: ";
            std::getline(std::cin, data);
            storageManager.save(key, data);
            break;

        case 4:
            std::cout << "Enter key: ";
            std::getline(std::cin, key);
            std::cout << "Loaded data: " << storageManager.load(key) << '\n';
            break;

        case 5:
            std::cout << "Keys in storage:\n";
            for (const auto& k : storageManager.listKeys()) {
                std::cout << k << '\n';
            }
            break;

        case 6:
            std::cout << "Enter key to remove: ";
            std::getline(std::cin, key);
            storageManager.remove(key);
            break;

        case 7:
            return;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
