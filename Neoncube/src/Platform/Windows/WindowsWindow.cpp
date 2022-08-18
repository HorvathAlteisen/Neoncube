#include "WindowsWindow.hpp"

namespace Hermes
{
    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        // Note: If you call that code from a DLL, it'll return the HINSTANCE of the EXE file that has loaded the DLL, not of the DLL itself.
        HINSTANCE hInstance = GetModuleHandle(NULL);
        WNDCLASSEXA windowClass;

        // Zeroes variable, just a windows thing
        SecureZeroMemory(&windowClass, sizeof(WNDCLASSEXA));

        windowClass.cbSize = sizeof(WNDCLASSEXA);
        windowClass.style = CS_OWNDC;
        windowClass.lpfnWndProc = Dispatcher;
        windowClass.cbClsExtra = 0;
        windowClass.cbWndExtra = 0;
        windowClass.hInstance = hInstance;
        //windowClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));
        windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        // windowClass.hbrBackground	= (HBRUSH)GetStockObject(NULL_BRUSH);
        windowClass.hbrBackground = CreateSolidBrush((COLORREF)props.backgroundColor);
        windowClass.lpszMenuName = NULL;
        windowClass.lpszClassName = props.className.c_str();
        //windowClass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));

        RegisterClassExA(&windowClass);

        m_hWindow = CreateWindowExA(0,
                                    props.className.c_str(),
                                    props.WindowName.c_str(),
                                    WS_POPUP,
                                    // Centers window on the screen
                                    ((WORD)GetSystemMetrics(SM_CXSCREEN) - props.width) / 2,
                                    ((WORD)GetSystemMetrics(SM_CYSCREEN) - props.height) / 2,
                                    props.width, props.height,
                                    NULL, NULL,
                                    hInstance, NULL);

        Show(1);
    }

    HWND *WindowsWindow::getHandle()
    {
        return &m_hWindow;
    }

    void WindowsWindow::Show(int nCmdShow)
    {
        // nCmdShow: https://docs.microsoft.com/de-de/windows/win32/api/winuser/nf-winuser-showwindow?redirectedfrom=MSDN
        ShowWindow(m_hWindow, nCmdShow);
    }

    LRESULT CALLBACK WindowsWindow::Dispatcher(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam)
    {
        WindowsWindow *window;

        // What the fuck...
        // Sources
        // German: https://www.c-plusplus.net/forum/topic/39356/wndproc-in-eine-klasse-bekommen/7
        // English: https://elcharolin.wordpress.com/2015/01/24/wndproc-as-a-class-member-win32/
        if (message == WM_CREATE)
        {
            // When the window is created, lParam contains a pointer to the current class instance. We cast it and asign it to a pointer to the class
            // That way we can access its members from a static context (as MessageRouter's)
            window = (WindowsWindow *)(((LPCREATESTRUCT)lParam)->lpCreateParams);
            // We store the reteived pointer to the window extra data space for it to be available later
            SetWindowLongPtr(handleWindow, GWLP_USERDATA, (LONG_PTR)window);
        }
        else
        {
            // If the window has been created we recover the class pointer from the window extra data space
            window = (WindowsWindow *)GetWindowLongPtr(handleWindow, GWLP_USERDATA);
        }

        return window->Callback(handleWindow, message, wParam, lParam);
    }

    LRESULT CALLBACK WindowsWindow::Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(handleWindow, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(handleWindow, &ps);
        }

        return DefWindowProc(handleWindow, message, wParam, lParam);
    }
}