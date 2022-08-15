#include "Application.hpp"
#include "Window.hpp"

namespace Hermes {
    Application::Application()
    {
        WindowProps props = {};
        m_Window = Window::Create(props);
    }

    void Application::Run()
    {

    }
}