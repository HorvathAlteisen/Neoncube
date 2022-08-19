#include <windows.h>
#include <commctrl.h>

#include "Core/Application.hpp"
#include "Core/Window.hpp"

LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam);

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
    InitCommonControls();
    OleInitialize(NULL);

    Hermes::WindowProps props = {};

    props.className = "Hermes";
    props.height = 640;
    props.width = 1000;
    props.WindowName = "Hermes Patcher";
    props.backgroundColor = 0x000000;

    Hermes::Application *app;

    app = new Hermes::Application();

    /*HINSTANCE _hInstance = GetModuleHandle(NULL);
    WNDCLASSEXA windowClass;
    HWND m_hWindow;

    // Zeroes variable, just a windows thing
    SecureZeroMemory(&windowClass, sizeof(WNDCLASSEXA));

    windowClass.cbSize = sizeof(WNDCLASSEXA);
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = Callback;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = _hInstance;
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
        _hInstance, NULL);

    ShowWindow(m_hWindow, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }*/
}

LRESULT CALLBACK Callback(HWND handleWindow, uint32_t message, WPARAM wParam, LPARAM lParam)
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
        return 0;
    }

    return DefWindowProc(handleWindow, message, wParam, lParam);
}