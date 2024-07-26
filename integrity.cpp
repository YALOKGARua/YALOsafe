#include "integrity.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

unsigned int IntegrityChecker::crc32(const std::string& data) {
    static unsigned int crc_table[256] = { 0 };
    if (crc_table[1] == 0) {
        for (unsigned int i = 0; i < 256; ++i) {
            unsigned int crc = i;
            for (unsigned int j = 8; j > 0; --j) {
                if (crc & 1)
                    crc = (crc >> 1) ^ 0xEDB88320;
                else
                    crc >>= 1;
            }
            crc_table[i] = crc;
        }
    }
    unsigned int crc = 0xFFFFFFFF;
    for (const auto& byte : data) {
        crc = (crc >> 8) ^ crc_table[(crc & 0xFF) ^ static_cast<unsigned char>(byte)];
    }
    return crc ^ 0xFFFFFFFF;
}

bool IntegrityChecker::checkIntegrity(const std::string& filePath, const std::string& expectedHash) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for integrity check: " << filePath << '\n';
        return false;
    }

    std::ostringstream oss;
    oss << file.rdbuf();
    std::string fileContent = oss.str();

    unsigned int hash = crc32(fileContent);

    std::ostringstream hashStream;
    hashStream << std::hex << std::setw(8) << std::setfill('0') << hash;

    return hashStream.str() == expectedHash;
}
