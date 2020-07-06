#include "Events.hpp"

namespace automation::sdl
{

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

} // namespace automation::sdl
