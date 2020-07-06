#include "Renderer.hpp"

#include "detail.hpp"

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

    void Renderer::clear()
    {
        detail::sdl_assert(SDL_RenderClear, m_ptr);
    }

    void Renderer::present()
    {
        SDL_RenderPresent(m_ptr);
    }

} // namespace automation::sdl
