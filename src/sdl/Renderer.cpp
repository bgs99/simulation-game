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

    auto Renderer::get() -> SDL_Renderer *
    {
        return m_ptr;
    }

    auto Renderer::move(util::Vector2d offset) -> void
    {
        m_pos += offset;
    }

    auto Renderer::set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha) -> void
    {
        detail::sdl_assert(SDL_SetRenderDrawColor, m_ptr, red, green, blue, alpha);
    }

    auto Renderer::load_texture(const fs::path &path) -> Texture &
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

    auto Renderer::render_texture(const std::filesystem::path &texture, util::Vector2d position) -> void
    {
        SDL_Rect destination;
        destination.h = destination.w = 48;
        position -= m_pos;
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

    auto Renderer::clear() -> void
    {
        detail::sdl_assert(SDL_RenderClear, m_ptr);
    }

    auto Renderer::present() -> void
    {
        SDL_RenderPresent(m_ptr);
    }

} // namespace automation::sdl
