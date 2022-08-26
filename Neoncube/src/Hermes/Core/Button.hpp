#pragma once

#include "Window.hpp"

namespace Hermes
{
    struct ButtonProps : WindowProps
    {
        uint16_t x;
        uint16_t y;
    };

    class Button
    {
    public:
        static Button *Create(Window *parentWindow, ButtonProps props);
    };
}