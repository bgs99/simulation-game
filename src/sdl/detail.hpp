#pragma once

#include <SDL2/SDL.h>

#include <iostream>

namespace automation::sdl::detail
{
    template <typename T>
    bool rv_fail(T arg)
    {
        return !arg;
    }

    template <>
    bool rv_fail<int>(int arg);

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

} // namespace automation::sdl::detail
