#pragma once

#include "sdl/SDLWrappers.hpp"

namespace automation::engine
{

    class Entity
    {
    public:
        virtual void handle_event(SDL_Event event) = 0;
        virtual void update() = 0;
        virtual void render(sdl::RendererWrapper &renderer) = 0;
    };

} // namespace automation::engine
