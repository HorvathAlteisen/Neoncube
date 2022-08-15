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
    public:
        WindowsWindow(const WindowProps &props);

    private:
        bool InitInstance();
    };
}