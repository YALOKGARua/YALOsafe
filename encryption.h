#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class EncryptionModule {
public:
    EncryptionModule(char key);
    std::string encrypt(const std::string& data, char key) const;
    std::string decrypt(const std::string& data, char key) const;

private:
    char encryptionKey;
};

#endif