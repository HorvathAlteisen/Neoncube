
namespace Hermes {
    class WindowsWindow
    {
        public:
            virtual ~Window = default;

            virtual void OnUpdate() = 0;

            virtual uint32_t GetWidth const = 0;
            virtual uint32_t GetHeight const = 0;

            static Window Create(const WindowProperties props = WindowProperties())
    };
}