#include "Application.hpp"
#include "Window.hpp"

namespace Hermes
{
    Application::Application()
    {
    }

    void Application::Run()
    {
        if (!InitInstance())
        {
            Window::MessageBox(nullptr, "Application already running...", "Error", MB_OK | MB_ICONINFORMATION);
        }

        // initialize common controls
        InitCommonControls();

        // initialize OLE
        if (FAILED(OleInitialize(NULL)))
            PostError(TRUE, "Failed to initialize OLE");

        std::error_code &ec;
        std::fs::create_directory("neoncube", ec);
        if (ec != std::errc::)
        {
        }

        WindowProps props = {};

        m_Window = Window::Create(props);
    }

    bool InitInstance()
    {
        HANDLE hMutex;
        hMutex = CreateMutex(NULL, TRUE, "GlobalMutex");

        switch (GetLastError())
        {

        case ERROR_SUCCESS:
            return true;

        case ERROR_ALREADY_EXISTS:
            return false;
        }

        return false;
    }
}