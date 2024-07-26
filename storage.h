#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>

class Storage {
public:
    Storage(char someParameter);
    std::string generateFileName(const std::string& key) const;
    std::vector<std::string> listKeys() const;
    void remove(const std::string& key);
    std::string load(const std::string& key) const;
    void save(const std::string& key, const std::string& data);

private:
    char parameter;
};

#endif // STORAGE_H
