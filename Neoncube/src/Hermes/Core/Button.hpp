#pragma once

#include "Window.hpp"

namespace Hermes
{
    struct ButtonProps : WindowProps
    {
        uint16_t x;
        uint16_t y;
    }; 

    class Button : public Window
    {
        public:
        static std::unique_ptr<Button> Create(Window parentWindow, ButtonProps props);

        private:
            Window* m_Window;
    };
}