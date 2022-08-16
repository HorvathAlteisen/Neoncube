#pragma once

#include "Window.hpp"

namespace Hermes
{
    struct ButtonProps
    {
        uint16_t x;
        uint16_t y;
        uint16_t height;
        uint16_t width;
    }; 

    class Button
    {
        public:
        static std::unique_ptr<Button> Create(Window window, ButtonProps props);

        private:
            Window m_Window;
    };
}