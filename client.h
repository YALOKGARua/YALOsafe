#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    void sendRequest(const std::string& key, const std::string& data);
    std::string fetchData(const std::string& key);
private:
    std::string serverAddress = "localhost";
};

#endif 
