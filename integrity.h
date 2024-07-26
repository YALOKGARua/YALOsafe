#ifndef INTEGRITY_H
#define INTEGRITY_H

#include <string>

class IntegrityChecker {
public:
    static unsigned int crc32(const std::string& data);
    static bool checkIntegrity(const std::string& filePath, const std::string& expectedHash);
};

#endif // INTEGRITY_H
