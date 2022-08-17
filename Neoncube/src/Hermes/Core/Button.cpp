#include "Button.hpp"
#include "Platform/Windows/WindowsButton.hpp"

namespace Hermes
{
    std::unique_ptr<Button> Button::Create(Window parentWindow, ButtonProps props)
    {
        #ifdef _WIN32
        return std::unique_ptr<Button>(WindowsButton(parentWindow, props));
        #else
        #error Currently Windows only!
        #endif
        return
    }
}