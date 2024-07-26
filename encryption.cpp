#include "encryption.h"

EncryptionModule::EncryptionModule(char key) : encryptionKey(key) {}

std::string EncryptionModule::encrypt(const std::string& data, char key) const {
    std::string encrypted = data;
    for (char& c : encrypted) {
        c ^= key;
    }
    return encrypted;
}

std::string EncryptionModule::decrypt(const std::string& data, char key) const {
    return encrypt(data, key);
}
