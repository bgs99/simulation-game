#pragma once

#include "sdl/Renderer.hpp"
#include "sdl/Texture.hpp"

#include <SDL2/SDL.h>

#include <filesystem>
#include <map>

namespace automation::engine
{

    class TextureManager
    {
    public:
        TextureManager(sdl::Renderer &renderer);

        sdl::Texture &load_texture(const std::filesystem::path &path);

    private:
        std::map<std::filesystem::path, sdl::Texture> m_cache;
        sdl::Renderer &m_renderer;
    };

} // namespace automation::engine
