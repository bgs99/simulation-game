#pragma once

#include <SDL2/SDL.h>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

constexpr const char *WINDOW_TITLE = "Automation";

namespace automation::sdl
{

    class SDL
    {
    public:
        SDL();
        ~SDL();
    };

} // namespace automation::sdl
