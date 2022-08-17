#pragma once
#include <cstdint>

#ifdef _WIN32
#include <Windows.h>
#undef MessageBox
#endif

#include "Core/Window.hpp"

namespace Hermes
{
    class WindowsWindow : Window
    {
    private:
        HWND m_hWindow;

    public:
        WindowsWindow(const WindowProps &props);
        HWND *getHandle();
        void Show(int nCmdShow);

    private:
        bool InitInstance();
        LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
        static LRESULT CALLBACK Dispatcher(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
    }
}