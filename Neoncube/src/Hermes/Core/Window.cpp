#include "Core/Window.hpp"

namespace Hermes
{
    std::unique_ptr<Window> Window::Create(const WindowProps& props)
    {

        return std::make_unique<Window>(props);
    }
}