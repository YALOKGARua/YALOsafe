#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include "encryption.h"

class Storage {
public:
    Storage(char someParameter);

    std::string generateFileName(const std::string& key) const;
    std::vector<std::string> listKeys() const;
    void remove(const std::string& key);
    std::string load(const std::string& key) const;
    void save(const std::string& key, const std::string& data);

private:
    EncryptionModule encryptionModule;
    std::string storagePath;
};

#endif
