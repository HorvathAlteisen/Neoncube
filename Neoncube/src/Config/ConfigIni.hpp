#include <Windows.h>
#include <string>
#include "Config.hpp"

#define MAXARRSIZE 1024

class ConfigIni : Config {
private:
    std::string configFile;
    struct inisetting
    {
        TCHAR szServerName[100];
        TCHAR szNoticeURL[MAXARRSIZE];
        TCHAR szPatchURL[MAXARRSIZE];
        TCHAR szPatchList[MAXARRSIZE];
        TCHAR szExecutable[256];
        TCHAR szPatchFolder[MAXARRSIZE];
        TCHAR szRegistration[MAXARRSIZE];
        TCHAR szGrf[50];
        TCHAR szSkin[256];
        WORD nBackupGRF;
        WORD nStartupOption;
        TCHAR szRagExeCall[MAXARRSIZE];
        UINT nPatchPort;

        UINT fDebugMode;
        TCHAR szRarPassword[MAXARRSIZE];
    };

public:
    ConfigIni(std::string configFilePath);
    virtual std::string getString(std::string section, std::string Key) override;
    virtual int getInt(std::string section, std::string Key) override;
};