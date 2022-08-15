#include <memory>

#include "Core/Window.hpp"

namespace Hermes {
    class Application {
        private:
        std::unique_ptr<Window> m_Window;
        public:
        Application();
        void Run();
    };
}