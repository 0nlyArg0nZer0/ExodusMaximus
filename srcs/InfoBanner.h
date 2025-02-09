#pragma once                                                                                                            // Ensures the header file is included only once during compilation
    
#include "includes.h"                                                                                                      // Includes necessary dependencies (assumed to be in "includes.h")

                                                                                                                  // Class responsible for creating and displaying an info banner
class InfoBanner
{
public:
                                                                                                                // Default message to be displayed if no custom message is provided
    inline static const std::string defaultMessage = 
        "Discord: 0nlyArg0n2        \n"
        "GitHub: https://github.com/0nlyArg0nZer0\n\n\n"
        "Thx to Erarnitox && loab <3";


                                                                                                
    
    // Function to create and show the info banner window
    static void Show(const std::string& message = defaultMessage)
    {
        // Define and register a window class
        WNDCLASSA wc = { 0 };
        wc.lpfnWndProc = WndProc;                                                                                            // Set the window procedure (callback function)
        wc.hInstance = GetModuleHandle(NULL);                                                                       // Get the handle of the current application instance
        wc.lpszClassName = "InfoBannerClass";                                // Set the class name for the window
        wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);                                                                          // Setzt das Standard-Info-Icon
        RegisterClassA(&wc);                                     // Register the window class

                                                                 // Create the actual window
        HWND hwnd = CreateWindowExA(
            WS_EX_TOPMOST | WS_EX_TOOLWINDOW,                   // Keeps window on top and hides it from the taskbar
            "InfoBannerClass",                                  // The class name we just registered
            "Info",  // Window title
            WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX | WS_SYSMENU,                // Standard window style but without resizing ability
            CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,             // Default position and size (400x200 pixels)
            NULL, NULL, GetModuleHandle(NULL), NULL             // Parent, menu, instance handle, additional params
        );

                                                                // Check if window creation failed
        if (!hwnd)
        {
            MessageBoxA(NULL, "Window could not be created!", "Error", MB_OK | MB_ICONERROR);
            return;
        }

                                                                        // Store the message string inside the window's user data
        SetWindowLongPtrA(hwnd, GWLP_USERDATA, (LONG_PTR)new std::string(message));

                                                                            // Show and refresh the window
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);

                                                                        // Message loop to keep the window open and responsive
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);                                     // Translate keyboard input messages
            DispatchMessage(&msg);                                       // Send messages to WndProc
        }

                                                                    // Free allocated memory for the message string after the window is closed
        delete (std::string*)GetWindowLongPtrA(hwnd, GWLP_USERDATA);
    }



	

private:
                                                                     // Window procedure (handles events like painting and closing)
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        switch (msg)
        {
        case WM_PAINT:                                                       // When the window needs to be redrawn
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Draw the text message
            std::string* message = (std::string*)GetWindowLongPtrA(hwnd, GWLP_USERDATA);
            RECT rect;
            GetClientRect(hwnd, &rect);
            DrawTextA(hdc, message->c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_WORDBREAK);

            // Load and draw the info icon
            HICON hIcon = LoadIcon(NULL, IDI_INFORMATION);
            DrawIcon(hdc, rect.left + 175, rect.top + 200, hIcon);

            EndPaint(hwnd, &ps);                               // Finish painting
            break;
        }
        case WM_CLOSE:                                                                      // When the close button is clicked
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:                                                                         // When the window is destroyed
            PostQuitMessage(0);                                                                     // Exit the message loop
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);  // Default message processing
        }
        return 0;
    }
};