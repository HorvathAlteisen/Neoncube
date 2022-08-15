#pragma once

#include <memory>
#include <string>
#include <utility>

#ifdef _WIN32
#include <Windows.h>
#undef MessageBox
#endif

namespace Hermes
{
    struct WindowProps
    {
    };

    class Window
    {
    public:
        static std::unique_ptr<Window> Create(const WindowProps &props = WindowProps());
        static uint8_t MessageBox(Window *window, std::string text, std::string caption, uint32_t type);
        static uint8_t MessageBox(Window *window, std::wstring text, std::wstring caption, uint32_t type);
    };
}