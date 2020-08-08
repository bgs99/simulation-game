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

        auto get() -> SDL_Renderer *;

        auto move(util::Vector2d offset) -> void;

        auto set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha = 255) -> void;
        auto render_texture(const std::filesystem::path &texture, util::Vector2d position) -> void;
        auto clear() -> void;
        auto present() -> void;

    private:
        auto load_texture(const std::filesystem::path &path) -> Texture &;

        SDL_Renderer *m_ptr;
        std::map<std::filesystem::path, std::unique_ptr<sdl::Texture>> m_cache;
        util::Vector2d m_pos;
    };

} // namespace automation::sdl
