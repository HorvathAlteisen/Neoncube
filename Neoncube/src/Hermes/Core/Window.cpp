#include "Window.hpp"
#include <utility>

namespace Hermes
{
    std::unique_ptr<Window> Window::Create(const WindowProps &props)
    {

        return std::unique_ptr<Window>(&props);
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