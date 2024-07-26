#include "settings.h"
#include <fstream>
#include <sstream>

Settings::Settings() {}

Settings::Settings(const std::string& filePath) : configFilePath(filePath) {
    load(filePath); // Завантажити налаштування при створенні об'єкта
}

void Settings::load(const std::string& filePath) {
    configFilePath = filePath;
    std::ifstream file(filePath);
    if (!file) return;
    std::string line;
    while (std::getline(file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            settings[key] = value;
        }
    }
}

void Settings::save(const std::string& filePath) {
    configFilePath = filePath;
    std::ofstream file(filePath);
    for (const auto& pair : settings) {
        file << pair.first << "=" << pair.second << "\n";
    }
}

void Settings::set(const std::string& key, const std::string& value) {
    settings[key] = value;
}

std::string Settings::get(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return ""; // Повертаємо порожній рядок, якщо ключ не знайдено
}
