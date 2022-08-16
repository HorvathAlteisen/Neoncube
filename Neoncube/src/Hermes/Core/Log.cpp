#include "Log.hpp"

namespace Hermes
{        
    void Log::Debug(std::string fmt, T t, Args... args)
    {
        va_list args;
        TCHAR buf[1024];

        va_start(args, fmt);
        vsprintf(buf, fmt, args);
        va_end(args);

        //FILE *f;
        //f = fopen("neoncube\\debug.log", "a");

        writeLog(buf, "neoncube\\debug.log");

        /*if (f != NULL)
        {
            fwrite(buf, 1, strlen(buf), f);
            fclose(f);
        }*/
    }

    void Log::Error(std::string fmt, T t, Args... args)
    {
        va_list args;
        TCHAR buf[1024];

        va_start(args, fmt);
        vsprintf(buf, fmt, args);
        va_end(args);

        //FILE *f;

        fs.open("neoncube\\error.log", std::fstream::app)
        //f = fopen("neoncube\\error.log", "a");

        writeLog(buf, "neoncube\\error.log");

        /*if (f != NULL)
        {
            fwrite(buf, 1, strlen(buf), f);
            fclose(f);
        }*/
    }

    void Log::writeLog(std::string message, std::filesystem::path filepath)
    {
        std::fstream fs;

        fs.open(filepath, std::fstream::app);

        if(!fs.is_open())
        {
            fs << message << std::endl;
            fs.close();
        }
    }
}