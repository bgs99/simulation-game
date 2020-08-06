#pragma once

#include "Texture.hpp"
#include "Window.hpp"

#include "util/Vector2d.hpp"

#include <SDL2/SDL.h>

#include <filesystem>
#include <map>

namespace automation::sdl
{

    class Renderer
    {
    public:
        Renderer(Window &);
        ~Renderer();

        SDL_Renderer *get();

        void set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha = 255);
        void render_texture(const std::filesystem::path & texture, util::Vector2d position);
        void clear();
        void present();

    private:
        Texture &load_texture(const std::filesystem::path & path);

        SDL_Renderer *m_ptr;
        std::map<std::filesystem::path, std::unique_ptr<sdl::Texture>> m_cache;
    };

} // namespace automation::sdl
