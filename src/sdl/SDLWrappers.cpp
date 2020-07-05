#include "SDLWrappers.hpp"

#include <iostream>

namespace automation::sdl
{
    template <typename T>
    bool rv_fail(T arg)
    {
        return !arg;
    }

    template <>
    bool rv_fail<int>(int arg)
    {
        return arg < 0;
    }

    template <typename Func, typename... Args>
    auto sdl_assert(Func func, Args... args)
    {
        auto res = func(args...);
        if (rv_fail(res))
        {
            auto error = SDL_GetError();
            std::cerr << error << std::endl;
            throw error;
        }
        return res;
    }

    std::vector<SDL_Event> get_events()
    {
        std::vector<SDL_Event> events;
        SDL_Event t;
        while (SDL_PollEvent(&t) == 1)
        {
            events.push_back(t);
        }
        return events;
    }

    //--------------------SDLWrapper definition---------------------//
    SDLWrapper::SDLWrapper()
    {
        sdl_assert(SDL_Init, SDL_INIT_EVERYTHING);
    }

    SDLWrapper::~SDLWrapper()
    {
        SDL_Quit();
    }

    //--------------------WindowWrapper definition---------------------//

    WindowWrapper::WindowWrapper(SDLWrapper &)
    {
        m_ptr = sdl_assert(
            SDL_CreateWindow,
            WINDOW_TITLE,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    }

    WindowWrapper::~WindowWrapper()
    {
        SDL_DestroyWindow(m_ptr);
    }

    SDL_Window *WindowWrapper::get()
    {
        return m_ptr;
    }

    //-------------------------RendererWrapper definition----------------//
    RendererWrapper::RendererWrapper(WindowWrapper &window)
    {
        m_ptr = sdl_assert(SDL_CreateRenderer, window.get(), -1, 0);
    }

    RendererWrapper::~RendererWrapper()
    {
        SDL_DestroyRenderer(m_ptr);
    }

    SDL_Renderer *RendererWrapper::get()
    {
        return m_ptr;
    }

    void RendererWrapper::set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha)
    {
        sdl_assert(SDL_SetRenderDrawColor, m_ptr, red, green, blue, alpha);
    }

    void RendererWrapper::clear()
    {
        sdl_assert(SDL_RenderClear, m_ptr);
    }

    void RendererWrapper::present()
    {
        SDL_RenderPresent(m_ptr);
    }

} // namespace automation::sdl
