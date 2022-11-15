#include <Windows.h>
#include <string>

#include "neondef.h"
#include "IConfig.hpp"
#include "IConfigData.hpp"

namespace Hermes
{
    class ConfigIni : public IConfig
    {
    public:
        ConfigIni(std::string filepath);
        IConfigData get(std::string) override;
        void operator[](std::string key) override
        {
            get(key);
        }

    private:
        int ReadFile(const std::string filepath) override;
        CFFE_ERROR CheckFileForExistance(LPCTSTR lpszFileName);
    };
}