#include "Notification.hpp"

namespace CUtils
{
    void SetConsoleColor(int color_a)
    {
#if defined (_WIN32) || defined(_WIN64)
        HANDLE h_console_ = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h_console_, color_a);
#else
        std::cout << "\033[" << color_a << "m";
#endif
    }

    void ResetConsoleColor()
    {
#if defined(_WIN32) || defined(_WIN64)
        SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
        std::cout << "\033[0m";
#endif
    }

    void Notification::Notify(NotificationType type_a, 
                              const std::string& message_a)
    {
        switch (type_a)
        {
        case TYPE_ERROR:
#if defined(_WIN32) || defined(_WIN64)
            SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
#else
            SetConsoleColor(31);
#endif
            std::cout << "ERROR: " << message_a << std::endl;
            break;

        case TYPE_WARNING:
#if defined(_WIN32) || defined(_WIN64)
            SetConsoleColor(FOREGROUND_RED   | 
                            FOREGROUND_GREEN |
                            FOREGROUND_INTENSITY);
#else
            SetConsoleColor(33);
#endif
            std::cout << "WARNING: " << message_a << std::endl;
            break;

        case TYPE_INFO:
#if defined(_WIN32) || defined(_WIN64)
            SetConsoleColor(FOREGROUND_GREEN | 
                            FOREGROUND_BLUE  | 
                            FOREGROUND_INTENSITY);
#else
            SetConsoleColor(0);
#endif
            std::cout << "INFO: " << message_a << std::endl;
            break;

        default:
            std::cerr << "Unknown notification type!" << std::endl;
            break;
        }
        
        ResetConsoleColor();
    }
} // namespace CUtils