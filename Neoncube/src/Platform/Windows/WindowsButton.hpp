#include "Hermes/Core/Button.hpp"
#include "WindowsWindow.hpp"

namespace Hermes
{
    class WindowsButton : public Button
    {
    private:
        WindowsWindow *m_Parent;
        HWND m_hButton;

    public:
        WindowsButton(WindowsWindow *parent, ButtonProps props);
        void Show(int nCmdShow);

    private:
        static LRESULT CALLBACK Dispatcher(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
        LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);
    };
}