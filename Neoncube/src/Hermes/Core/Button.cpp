#include "Button.hpp"
#include "Platform/Windows/WindowsButton.hpp"

namespace Hermes
{
    Button *Button::Create(Window *parentWindow, ButtonProps props)
    {
#ifdef _WIN32
        return new WindowsButton(dynamic_cast<WindowsWindow *>(parentWindow), props);
#else
#error Currently Windows only!
#endif
        return nullptr;
    }
}