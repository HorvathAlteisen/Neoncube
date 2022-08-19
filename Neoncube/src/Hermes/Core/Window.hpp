#pragma once

#include <memory>
#include <string>
#include <utility>
#include <functional>

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

    class Window
    {
    public:
        //using EventCallbackFn = std::function<void(Event&)>;
        static Window* Create(const WindowProps &props);
        static uint8_t MessageBox(Window *window, std::string text, std::string caption, uint32_t type);
        static uint8_t MessageBox(Window *window, std::wstring text, std::wstring caption, uint32_t type);
        virtual void OnUpdate() = 0;

        //virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    };
}