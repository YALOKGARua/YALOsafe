#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class EncryptionModule {
public:
    std::string encrypt(const std::string& data, char key);
    std::string decrypt(const std::string& data, char key);
};

#endif