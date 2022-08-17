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
        std::string className;
        std::string WindowName;
        uint16_t width;
        uint16_t height;
        uint32_t backgroundColor;
    };

    struct RGB
    {
        RGB(const uint32_t hexColor) {
            r = ((hexColor >> 16) & 0xFF) / 255.0;  // Extract the RR byte
            g = ((hexColor >> 8) & 0xFF) / 255.0;   // Extract the GG byte
            b = ((hexColor ) & 0xFF) / 255.0;        // Extract the BB byte
        }
        uint8_t r;
        uint8_t g;
        uint8_t b;
    }

    class Window
    {
    public:
        static std::unique_ptr<Window> Create(const WindowProps &props = WindowProps());
        static uint8_t MessageBox(Window *window, std::string text, std::string caption, uint32_t type);
        static uint8_t MessageBox(Window *window, std::wstring text, std::wstring caption, uint32_t type);
    };
}