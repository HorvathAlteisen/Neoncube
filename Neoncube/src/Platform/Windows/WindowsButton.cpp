#include <Windows.h>
#include "WindowsButton.hpp"
#include <iostream>

namespace Hermes
{
    WindowsButton::WindowsButton(WindowsWindow *parent, ButtonProps props) : m_Parent(parent)
    {
        // Note: If you call that code from a DLL, it'll return the HINSTANCE of the EXE file that has loaded the DLL, not of the DLL itself.
        HINSTANCE hInstance = GetModuleHandle(NULL);
        WNDCLASSEXA windowClass;

        // Zeroes variable, just a windows thing
        SecureZeroMemory(&windowClass, sizeof(WNDCLASSEXA));

        windowClass.cbSize = sizeof(WNDCLASSEXA);
        windowClass.style = CS_OWNDC | WS_CHILD;
        windowClass.lpfnWndProc = Dispatcher;
        windowClass.cbClsExtra = 0;
        windowClass.cbWndExtra = 0;
        windowClass.hInstance = hInstance;
        // windowClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));
        windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        // windowClass.hbrBackground	= (HBRUSH)GetStockObject(NULL_BRUSH);
        windowClass.hbrBackground = CreateSolidBrush(RGB(GetBValue(props.backgroundColor), GetGValue(props.backgroundColor), GetRValue(props.backgroundColor)));
        windowClass.lpszMenuName = NULL;
        windowClass.lpszClassName = props.className.c_str();
        // windowClass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON));

        RegisterClassExA(&windowClass);

        m_hButton = CreateWindowExA(0,
                                    "BUTTON",
                                    props.WindowName.c_str(),
                                    WS_CHILD | BS_OWNERDRAW | WS_VISIBLE,
                                    props.x,
                                    props.y,
                                    props.width, props.height,
                                    *m_Parent->getHandle(), NULL,
                                    (HINSTANCE)GetWindowLong(*m_Parent->getHandle(), GWL_HINSTANCE), NULL);

        Show(1);
    }

    void WindowsButton::Show(int nCmdShow)
    {
        ShowWindow(m_hButton, nCmdShow);
    }

    LRESULT CALLBACK WindowsButton::Dispatcher(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam)
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

            /*FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));*/

            EndPaint(handleWindow, &ps);
        }
        }
        return DefWindowProc(handleWindow, message, wParam, lParam);
    }

    LRESULT CALLBACK WindowsButton::Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam)
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

            /*FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));*/

            EndPaint(handleWindow, &ps);
        }
        }
        return DefWindowProc(handleWindow, message, wParam, lParam);
    }
}