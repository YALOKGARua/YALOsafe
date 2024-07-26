#include "logger.h"
#include <fstream>
#include <iostream>

Logger::Logger(const std::string& filePath) : logFilePath(filePath) {}

void Logger::log(const std::string& message) {
    std::ofstream file(logFilePath, std::ios_base::app);
    if (file) {
        file << message << '\n';
    }
    else {
        std::cerr << "Error opening log file: " << logFilePath << '\n';
    }
}
