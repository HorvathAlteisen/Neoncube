#include <Windows.h>
#include <string>
#include <map>
#include <filesystem>
#include <fstream>

#include <toml++/toml.h>

#include "Config.hpp"

namespace Hermes
{

    namespace fs = std::filesystem;

    class ConfigToml : Config<toml::v3::table>
    {
    public:
        ConfigToml(std::string filepath);
        virtual std::string getString(std::string section, std::string Key) override;
        virtual uint32_t getInt(std::string section, std::string Key) override;
        toml::v3::table ConfigToml::get() override;

    private:
        fs::path m_filePath;
        toml::v3::table m_configTable;
        virtual toml::v3::table ReadFile(const std::string filepath) override;
    };
}