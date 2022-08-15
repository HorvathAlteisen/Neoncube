#include "Log.hpp"

namespace Hermes
{
    void AddDebug(LPCTSTR fmt, ...)
    {
        va_list args;
        TCHAR buf[1024];

        va_start(args, fmt);
        vsprintf(buf, fmt, args);
        va_end(args);

        FILE *f;
        f = fopen("neoncube\\debug.log", "a");

        if (f != NULL)
        {
            fwrite(buf, 1, strlen(buf), f);
            fclose(f);
        }
    }

    void PostError(BOOL exitapp, LPCTSTR lpszErrMessage, ...)
    {
        DWORD dwError = GetLastError();
        va_list arg;
        TCHAR buf[1024];

        va_start(arg, lpszErrMessage);
        vsprintf(buf, lpszErrMessage, arg);
        va_end(arg);

        MessageBoxA(NULL, buf, "Error", MB_OK | MB_ICONERROR);
        lstrcatA(buf, "\n"); // new line for our error log
        AddErrorLog(buf);

        if (exitapp)
            ExitProcess(dwError);
    }
}