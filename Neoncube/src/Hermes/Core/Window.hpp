#include <memory>

namespace Hermes
{
    struct WindowProps
    {

    };

    class Window
    {
        public:
        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
    };
}