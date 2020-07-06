#include "SDL.hpp"

#include "detail.hpp"

namespace automation::sdl
{

    SDL::SDL()
    {
        detail::sdl_assert(SDL_Init, SDL_INIT_EVERYTHING);
    }

    SDL::~SDL()
    {
        SDL_Quit();
    }

} // namespace automation::sdl
