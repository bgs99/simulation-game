#include "Window.hpp"

#include "detail.hpp"

namespace automation::sdl
{

    Window::Window(SDL &)
    {
        m_ptr = detail::sdl_assert(
            SDL_CreateWindow,
            WINDOW_TITLE,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_ptr);
    }

    SDL_Window *Window::get()
    {
        return m_ptr;
    }
} // namespace automation::sdl
