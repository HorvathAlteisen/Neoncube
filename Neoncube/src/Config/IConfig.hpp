#include <string>

#include "IConfigValue.hpp"

namespace Hermes
{
    class IConfig
    {
    public:
        virtual IConfigData get(std::string) = 0;
        virtual void operator[](std::string key) = 0;

    private:
        virtual int ReadFile(const std::string filepath) = 0;
    };
}