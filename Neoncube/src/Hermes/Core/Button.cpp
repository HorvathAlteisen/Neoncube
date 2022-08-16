#include "Button.hpp"
#include "Platform/Windows/WindowsButton.hpp"

namespace Hermes
{
    std::unique_ptr<Button> Button::Create(Window window, ButtonProps props)
    {
        #ifdef _WIN32
        return std::unique_ptr<Button>(WindowsButton(props));
        #else
        #error Currently Windows only!
        #endif
        return
    }
}