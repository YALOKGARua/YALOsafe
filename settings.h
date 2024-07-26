#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <string>

class Settings {
public:
    Settings(); // ������ ����������� ��� ���������
    Settings(const std::string& filePath); // ����������� � ���������� ��� ����� �� �����
    void load(const std::string& filePath);
    void save(const std::string& filePath);
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
private:
    std::map<std::string, std::string> settings;
    std::string configFilePath; // ������ ��� ��������� ����� �� �����
};

#endif // SETTINGS_H
