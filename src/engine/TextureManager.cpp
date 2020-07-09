#include "TextureManager.hpp"

namespace fs = std::filesystem;

namespace automation::engine
{

    TextureManager::TextureManager(sdl::Renderer &renderer)
        : m_renderer{renderer}
    {
    }

    sdl::Texture &TextureManager::load_texture(const fs::path &path)
    {
        auto it = m_cache.find(path);

        if (it == m_cache.end())
        {
            it = m_cache.emplace(path, sdl::Texture{m_renderer, path}).first;
        }

        return it->second;
    }

} // namespace automation::engine
