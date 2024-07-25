#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    void start();
    void handleRequest();
private:
    void saveData(const std::string& key, const std::string& data);
    std::string loadData(const std::string& key) const;
};

#endif
