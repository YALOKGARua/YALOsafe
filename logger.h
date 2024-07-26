#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    Logger(const std::string& filename);
    void log(const std::string& message);
private:
    std::ofstream logFile;
    std::mutex logMutex;
};

#endif
