#pragma once

#include <string>
#include <fstream>
#include <filesystem>

namespace Hermes
{
    template<typename T, typename... Args>
    class Log
    {
        public:
        static void Debug(std::string fmt, T t, Args... args);
        static void Error(std::string fmt, T t, Args... args);

        private:
        static void writeLog(std::string message, std::filesystem::path path);
    };
}