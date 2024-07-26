#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "encryption.h"

class Storage {
public:
    Storage(char encryptionKey);
    void save(const std::string& key, const std::string& data);
    std::string load(const std::string& key) const;
    void remove(const std::string& key);
    std::vector<std::string> listKeys() const;
    std::string generateFileName(const std::string& key) const;

private:
    char encryptionKey;
    EncryptionModule encryptionModule;
};

#endif