#include "WindowsWindow.hpp"

namespace Hermes
{
    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        HWND hwnd;
        MSG message;
        INT iWidth = 1000;
        INT iHeight = 640;
        WNDCLASSEXA wc;

        if (!InitInstance())
        {
            MessageBoxA(NULL, "Application already running...", "Error", MB_OK | MB_ICONINFORMATION);
            return 0;
        }

        Init();
    }

    bool WindowsWindow::InitInstance()
    {
        HANDLE hMutex;
        hMutex = CreateMutex(NULL, TRUE, "GlobalMutex");

        switch (GetLastError())
        {

        case ERROR_SUCCESS:
            return true;

        case ERROR_ALREADY_EXISTS:
            return false;

        default:
            return false;
        }
    }

    bool Init()
    {
        // initialize common controls
        InitCommonControls();

        // initialize OLE
        if (FAILED(OleInitialize(NULL)))
            PostError(TRUE, "Failed to initialize OLE");

        CreateDirectoryA("neoncube", NULL);
        if (GetLastError() != ERROR_ALREADY_EXISTS)
        {
            MessageBoxA(NULL, "neoncube directory created, please copy files inside and configure!", NULL, MB_OK | MB_ICONINFORMATION);
            return -1;
        }
    }
}