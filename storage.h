#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    void save(const std::string& key, const std::string& data);
    std::string load(const std::string& key) const;
private:
    std::string generateFileName(const std::string& key) const;
};

#endif 
