#include <String>

class Config {
    virtual std::string getString(std::string section, std::string Key) = 0;
    virtual int getInt(std::string section, std::string Key) = 0;
};