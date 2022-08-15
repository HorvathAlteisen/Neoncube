#include "iostream"

#include "ConfigToml.hpp"

namespace Hermes
{

    namespace Config
    {

    }

    ConfigToml::ConfigToml(std::string filepath) : m_filePath(filepath)
    {

        if (!fs::exists(m_filePath))
        {
            // Errorlog: file not found (" + m_PathConfigFile.generic_string() + ")\n"
            throw "file not found (" + m_filePath.generic_string() + ")\n";
        }

        if (m_filePath.has_parent_path())
        {
            if (!fs::is_directory(m_filePath.parent_path()))
            {
                // Errorlog invalid path (" + m_PathConfigFile.generic_string() + ")\n"
                throw "invalid path (" + m_filePath.generic_string() + ")\n";
            }
        }

        /*case CFFE_ACCESS_DENIED:
            AddErrorLog("access denied (neoncube\\neoncube.ini)\n");
            MessageBoxA(NULL, "access denied (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
            return -1;

        case CFFE_UNKNOWN_ERROR:
            AddErrorLog("unknown error (neoncube\\neoncube.ini)\n");
            MessageBoxA(NULL, "unknown error (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
            return -1;*/

        m_configTable = ReadFile(filepath);
    };

    std::string ConfigToml::getString(std::string section, std::string Key)
    {
        return "1";
    };

    uint32_t ConfigToml::getInt(std::string section, std::string Key)
    {
        return 1;
    };

    toml::v3::table ConfigToml::ReadFile(std::string filepath)
    {
        toml::v3::table table;

        try
        {
            table = toml::parse_file(filepath);
        }
        catch (const toml::parse_error err)
        {
            std::cerr << "Parsing failed:\n"
                      << err << "\n";
        }

        return table;
    }

    toml::v3::table ConfigToml::get()
    {
        return m_configTable;
    }
}