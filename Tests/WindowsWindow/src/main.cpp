#include <windows.h>
#include <commctrl.h>

#include "Core/Application.hpp"
#include "Core/Window.hpp"
#include "Platform/Windows/WindowsWindow.hpp"
#include "Core/Button.hpp"
#include "Config/ConfigToml.hpp"

#include <iostream>

LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);

/*int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
    InitCommonControls();

    Hermes::Window* window;
    Hermes::WindowProps props = {};
    Hermes::ConfigToml* config;
    Hermes::ConfigToml* style;

    /*props.className = "Hermes";
    props.height = 640;
    props.width = 1000;
    props.WindowName = "Hermes Patcher";
    props.backgroundColor = 0x000000;*/
/*

try {
    config = new Hermes::ConfigToml("neoncube\\neoncube.toml");
}
catch (std::string message)
{
    Hermes::Window::MessageBox(nullptr, message, "Error", MB_OK | MB_ICONINFORMATION);
}

Hermes::Window::MessageBox(nullptr, *config->get()["server"]["skin"], "Error", MB_OK | MB_ICONINFORMATION)

try {
    style = new Hermes::ConfigToml("neoncube\\" + config->get()["server"]["skin"] + "\\skin.toml");
}
catch (std::string message)
{
    Hermes::Window::MessageBox(nullptr, message, "Error", MB_OK | MB_ICONINFORMATION);
}

props.className = "Hermes";
props.className += "_CLASS";

props.WindowName = "Hermes - ";
props.WindowName += *style->get()["server"]["server_name"].value<std::string>();

props.width = (uint16_t)style->get()["window"]["minwidth"].as_integer();
props.height = (uint16_t)style->get()["window"]["minheight"].as_integer();
props.backgroundColor = (uint32_t)style->get()["window"][""].as_integer();

window = Hermes::Window::Create(props);

/*Hermes::Application *app;

app = new Hermes::Application();

HINSTANCE _hInstance = GetModuleHandle(NULL);
WNDCLASSEXA windowClass;
HWND m_hWindow;

// Zeroes variable, just a windows thing
SecureZeroMemory(&windowClass, sizeof(WNDCLASSEXA));

windowClass.cbSize = sizeof(WNDCLASSEXA);
windowClass.style = CS_OWNDC;
windowClass.lpfnWndProc = Callback;
windowClass.cbClsExtra = 0;
windowClass.cbWndExtra = 0;
windowClass.hInstance = _hInstance;
//windowClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));
windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
// windowClass.hbrBackground	= (HBRUSH)GetStockObject(NULL_BRUSH);
windowClass.hbrBackground = CreateSolidBrush((COLORREF)props.backgroundColor);
windowClass.lpszMenuName = NULL;
windowClass.lpszClassName = props.className.c_str();
//windowClass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));

RegisterClassExA(&windowClass);

m_hWindow = CreateWindowExA(0,
    props.className.c_str(),
    props.WindowName.c_str(),
    WS_POPUP,
    // Centers window on the screen
    ((WORD)GetSystemMetrics(SM_CXSCREEN) - props.width) / 2,
    ((WORD)GetSystemMetrics(SM_CYSCREEN) - props.height) / 2,
    props.width, props.height,
    NULL, NULL,
    _hInstance, NULL);

ShowWindow(m_hWindow, nCmdShow);

MSG msg = { };
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}*/

int main()
{
    InitCommonControls();

    Hermes::Window *window;
    Hermes::WindowProps props = {};
    Hermes::ConfigToml *config;
    Hermes::ConfigToml *style;
    Hermes::Button *button;
    Hermes::ButtonProps buttonProps = {};

    /*props.className = "Hermes";
    props.height = 640;
    props.width = 1000;
    props.WindowName = "Hermes Patcher";
    props.backgroundColor = 0x000000;*/

    try
    {
        config = new Hermes::ConfigToml("neoncube\\neoncube.toml");
    }
    catch (std::string message)
    {
        Hermes::Window::MessageBox(nullptr, message, "Error", MB_OK | MB_ICONINFORMATION);
    }

    try
    {
        style = new Hermes::ConfigToml("neoncube\\" + config->get()["server"]["skin"].value<std::string>().value() + "\\skin.toml");
    }
    catch (std::string message)
    {
        Hermes::Window::MessageBox(nullptr, message, "Error", MB_OK | MB_ICONINFORMATION);
    }

    props.className = "Hermes";
    props.className += "_CLASS";

    props.WindowName = "Hermes - ";
    props.WindowName += *config->get()["server"]["server_name"].value<std::string>();

    props.width = *style->get()["window"]["minwidth"].value<uint16_t>();
    props.height = *style->get()["window"]["minheight"].value<uint16_t>();
    props.backgroundColor = *style->get()["window"]["background_color"].value<uint32_t>();

    window = Hermes::Window::Create(props);

    buttonProps.backgroundColor = 0x0074E1;
    buttonProps.className = "STARTGAME";
    buttonProps.height = 56;
    buttonProps.width = 270;
    buttonProps.WindowName = "Play";
    buttonProps.x = 40;
    buttonProps.y = 503;

    button = Hermes::Button::Create(window, buttonProps);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}