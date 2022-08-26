#pragma once
#include <cstdint>

#ifdef _WIN32
#include <Windows.h>
#undef MessageBox
#endif

#include "Core/Window.hpp"

namespace Hermes
{
    class WindowsWindow : public Window
    {
    private:
        HWND m_hWindow;

    public:
        WindowsWindow(const WindowProps &props);
        // void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        HWND *getHandle();
        void Show(int nCmdShow);
        void OnUpdate() override;

    private:
        bool InitInstance();
        LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
        static LRESULT CALLBACK Dispatcher(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
    };
}