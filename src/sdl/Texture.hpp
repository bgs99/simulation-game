#pragma once

#include "Renderer.hpp"

#include <SDL2/SDL.h>

#include <filesystem>

namespace automation::sdl
{

    class Texture
    {
    public:
        Texture(Renderer &renderer, const std::filesystem::path &path);
        ~Texture();

        SDL_Texture *get();

    private:
        SDL_Texture *m_ptr;
    };

} // namespace automation::sdl