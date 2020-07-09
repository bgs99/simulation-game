#include "Texture.hpp"

#include "detail.hpp"

#include <SDL2/SDL_image.h>

namespace automation::sdl
{
    namespace fs = std::filesystem;

    Texture::Texture(Renderer &renderer, const fs::path &path)
    {
        m_ptr = detail::sdl_assert(IMG_LoadTexture, renderer.get(), path.c_str());
    }

    Texture::~Texture()
    {
        SDL_DestroyTexture(m_ptr);
    }

    SDL_Texture *Texture::get()
    {
        return m_ptr;
    }

} // namespace automation::sdl
