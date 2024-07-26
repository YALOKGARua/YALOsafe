#include "encryption.h"

EncryptionModule::EncryptionModule() : key("defaultKey") {}
EncryptionModule::EncryptionModule(const std::string& key) : key(key) {
}
