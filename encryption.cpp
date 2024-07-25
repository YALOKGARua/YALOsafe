#include "encryption.h"

std::string EncryptionModule::encrypt(const std::string& data, char key) {
    std::string result = data;
    for (char& c : result) {
        c ^= key;
    }
    return result;
}

std::string EncryptionModule::decrypt(const std::string& data, char key) {
  
    return encrypt(data, key);
}
