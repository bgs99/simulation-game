#include "Renderer.hpp"

#include "detail.hpp"

namespace fs = std::filesystem;

namespace automation::sdl
{

    Renderer::Renderer(Window &window)
    {
        m_ptr = detail::sdl_assert(SDL_CreateRenderer, window.get(), -1, 0);
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(m_ptr);
    }

    SDL_Renderer *Renderer::get()
    {
        return m_ptr;
    }

    void Renderer::set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha)
    {
        detail::sdl_assert(SDL_SetRenderDrawColor, m_ptr, red, green, blue, alpha);
    }

    Texture &Renderer::load_texture(const fs::path &path)
    {
        auto it = m_cache.find(path);

        if (it == m_cache.end())
        {
            it = m_cache.emplace(
                            path,
                            std::make_unique<sdl::Texture>(
                                *this, fs::path{"resources"} / path))
                     .first;
        }

        return *it->second;
    }

    void Renderer::render_texture(const std::filesystem::path &texture, util::Vector2d position)
    {
        SDL_Rect destination;
        destination.h = destination.w = 48;
        destination.x = position.x;
        destination.y = position.y;

        auto &l_texture = load_texture(texture);

        detail::sdl_assert(
            SDL_RenderCopyEx,
            this->get(),
            l_texture.get(),
            nullptr, &destination,
            0.0, nullptr,
            SDL_RendererFlip::SDL_FLIP_NONE);
    }

    void Renderer::clear()
    {
        detail::sdl_assert(SDL_RenderClear, m_ptr);
    }

    void Renderer::present()
    {
        SDL_RenderPresent(m_ptr);
    }

} // namespace automation::sdl
