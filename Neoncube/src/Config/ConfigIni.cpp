#include <io.h>
#include <iostream>
#include <fcntl.h>

#include "ConfigIni.hpp"

namespace Hermes
{
    ConfigIni::ConfigIni(std::string pathToFile) : m_PathConfigFile(pathToFile)
    {
        if (!fs::exists(m_PathConfigFile))
        {
            AddErrorLog("file not found (" + m_PathConfigFile.generic_string() + ")\n");
            MessageBoxA(NULL, "file not found (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
            return -1;
        }

        switch (fs::status(m_PathConfigFile))
        {
            
            case CFFE_PATH_NOT_FOUND:
                AddErrorLog("invalid path (neoncube\\neoncube.ini)\n");
                MessageBoxA(NULL, "path not found (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
                return -1;

            case CFFE_ACCESS_DENIED:
                AddErrorLog("access denied (neoncube\\neoncube.ini)\n");
                MessageBoxA(NULL, "access denied (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
                return -1;

            case CFFE_UNKNOWN_ERROR:
                AddErrorLog("unknown error (neoncube\\neoncube.ini)\n");
                MessageBoxA(NULL, "unknown error (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
                return -1;
        }

        LPSTR BUFFER = new CHAR[1024];
        GetPrivateProfileSectionNames(BUFFER, sizeof(BUFFER), m_PathConfigFile.c_str());
        //Devconsole();

        MessageBoxA(NULL,BUFFER, "Debug", NULL);
    };

    std::string ConfigIni::getString(std::string section, std::string Key)
    {
        return "1";
    };

    uint32_t ConfigIni::getInt(std::string section, std::string Key)
    {
        return 1;
    };

    void ConfigIni::Devconsole()
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        int consoleHandleR, consoleHandleW ;
        long stdioHandle;
        FILE *fptr;

        AllocConsole();
        std::string strW = "Dev Console";
        SetConsoleTitle( strW.c_str() );

        EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE , MF_GRAYED);
        DrawMenuBar(GetConsoleWindow());

        GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo );

        stdioHandle = (long)GetStdHandle( STD_INPUT_HANDLE );
        consoleHandleR = _open_osfhandle( stdioHandle, _O_TEXT );
        fptr = _fdopen( consoleHandleR, "r" );
        *stdin = *fptr;
        setvbuf( stdin, NULL, _IONBF, 0 );

        stdioHandle = (long) GetStdHandle( STD_OUTPUT_HANDLE );
        consoleHandleW = _open_osfhandle( stdioHandle, _O_TEXT );
        fptr = _fdopen( consoleHandleW, "w" );
        *stdout = *fptr;
        setvbuf( stdout, NULL, _IONBF, 0 );

        stdioHandle = (long)GetStdHandle( STD_ERROR_HANDLE );
        *stderr = *fptr;
        setvbuf( stderr, NULL, _IONBF, 0 );
    }
}