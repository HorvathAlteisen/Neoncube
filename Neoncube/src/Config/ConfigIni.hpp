#include <Windows.h>
#include <string>
#include <map>
#include <filesystem>

#include "Config.hpp"

namespace Hermes {

    namespace fs = std::filesystem;

    class ConfigIni : Config
    {
        private:
            fs::path m_PathConfigFile;
            std::map<std::string, std::map<std::wstring, std::wstring>> Config;

        public:
            ConfigIni(std::string configFilePath);
            virtual std::string getString(std::string section, std::string Key) override;
            virtual uint32_t getInt(std::string section, std::string Key) override;
            void Devconsole();
    };
}