#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <string>

class Settings {
public:
    Settings(); // Додано конструктор без параметрів
    Settings(const std::string& filePath); // Конструктор з параметром для шляху до файлу
    void load(const std::string& filePath);
    void save(const std::string& filePath);
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
private:
    std::map<std::string, std::string> settings;
    std::string configFilePath; // Додано для зберігання шляху до файлу
};

#endif // SETTINGS_H
