#pragma once

#include "Window.hpp"

#include <SDL2/SDL.h>

namespace automation::sdl
{

    class Renderer
    {
    public:
        Renderer(Window &);
        ~Renderer();

        SDL_Renderer *get();

        void set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha = 255);
        void clear();
        void present();

    private:
        SDL_Renderer *m_ptr;
    };

} // namespace automation::sdl
