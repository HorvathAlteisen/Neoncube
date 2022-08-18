#include "Window.hpp"
#include "Platform/Windows/WindowsWindow.hpp"
#include <utility>

namespace Hermes
{
    Window* Window::Create(const WindowProps &props)
    {
        #ifdef _WIN32
        return new WindowsWindow(props);
        #else
        #error Currently Windows only!
        #endif
    }

    uint8_t Window::MessageBox(Window *window, std::string text, std::string caption, uint32_t type)
    {
#ifdef _WIN32
        MessageBoxA(NULL, text.c_str(), caption.c_str(), type);
#endif
        return 1;
    }

    uint8_t Window::MessageBox(Window *window, std::wstring text, std::wstring caption, uint32_t type)
    {
#ifdef _WIN32
        MessageBoxW(NULL, text.c_str(), caption.c_str(), type);
#endif
        return 1;
    }
}