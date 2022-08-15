#pragma once

#include <String>

template <typename T>
class Config
{
public:
    virtual std::string getString(std::string section, std::string Key) = 0;
    virtual uint32_t getInt(std::string section, std::string Key) = 0;
    virtual T get() = 0;

private:
    virtual T ReadFile(const std::string filepath) = 0;
};