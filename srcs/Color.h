#pragma once
#include "includes.h"

namespace Color
{
    // Standardfarben
    constexpr std::string_view red = "\033[31m";
    constexpr std::string_view green = "\033[32m";
    constexpr std::string_view yellow = "\033[33m";
    constexpr std::string_view blue = "\033[34m";
    constexpr std::string_view magenta = "\033[35m";
    constexpr std::string_view cyan = "\033[36m";
    constexpr std::string_view white = "\033[37m";

    // Hintergrundfarben
    constexpr std::string_view bg_red = "\033[41m";
    constexpr std::string_view bg_green = "\033[42m";
    constexpr std::string_view bg_yellow = "\033[43m";
    constexpr std::string_view bg_blue = "\033[44m";
    constexpr std::string_view bg_magenta = "\033[45m";
    constexpr std::string_view bg_cyan = "\033[46m";
    constexpr std::string_view bg_white = "\033[47m";

    // Weitere erweiterte Farben (8-Bit Farben)
    constexpr std::string_view grey = "\033[90m";
    constexpr std::string_view bright_red = "\033[91m";
    constexpr std::string_view bright_green = "\033[92m";
    constexpr std::string_view bright_yellow = "\033[93m";
    constexpr std::string_view bright_blue = "\033[94m";
    constexpr std::string_view bright_magenta = "\033[95m";
    constexpr std::string_view bright_cyan = "\033[96m";
    constexpr std::string_view bright_white = "\033[97m";

    // Reset, um zurück zur Standardfarbe zu wechseln
    constexpr std::string_view reset = "\033[0m";

}
