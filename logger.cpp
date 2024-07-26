#include "logger.h"
#include <chrono>
#include <ctime>
#include <sstream>

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> guard(logMutex);
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[26];
    ctime_s(timeBuffer, sizeof(timeBuffer), &nowTime);
    logFile << timeBuffer << ": " << message << std::endl;
    if (!logFile) {
        throw std::runtime_error("Failed to write to log file");
    }
}
