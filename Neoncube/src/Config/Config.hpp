#include <String>

class Config {
    virtual std::string getString(std::string section, std::string Key) = 0;
    virtual uint32_t getInt(std::string section, std::string Key) = 0;
};