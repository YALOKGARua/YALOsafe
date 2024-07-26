#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class EncryptionModule {
public:
    EncryptionModule();
    EncryptionModule(const std::string& key);
private:
    std::string key;
};

#endif
