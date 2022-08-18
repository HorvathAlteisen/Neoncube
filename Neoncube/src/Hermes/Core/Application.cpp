#include "Application.hpp"
#include "Window.hpp"
#include "Config/ConfigToml.hpp"

namespace Hermes
{
    Application::Application()
    {
        Window* window;
        WindowProps props = {0};
        ConfigToml* config;
        ConfigToml* style;

        try {
            config = new ConfigToml("neoncube\\neoncube.toml");
        } catch(std::string message)
        {
            Window::MessageBox(nullptr, message, "Error", MB_OK | MB_ICONINFORMATION);
        }        

        props.className = "Hermes" + "_ClASS";
        props.WindowName = "Hermes - " + style.get()["server"][];
        props.width = config.get()["window"]["minwidth"];
        props.height = config.get()["window"]["minheight"];

        window = Window::Create(props);

        for(auto [k,v]: *config.get()["Buttons"].as_table())
        {
            Button
        }

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