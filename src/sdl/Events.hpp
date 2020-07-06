#pragma once

#include <SDL2/SDL.h>

#include <vector>

namespace automation::sdl
{

    std::vector<SDL_Event> get_events();

} // namespace automation::sdl
