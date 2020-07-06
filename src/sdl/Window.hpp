#pragma once

#include "SDL.hpp"

#include <SDL2/SDL.h>

namespace automation::sdl
{

    class Window
    {
    public:
        Window(SDL &);
        ~Window();

        SDL_Window *get();

    private:
        SDL_Window *m_ptr;
    };

} // namespace automation::sdl