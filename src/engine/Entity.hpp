#pragma once

#include "sdl/Events.hpp"
#include "sdl/Renderer.hpp"

namespace automation::engine
{

    class Entity
    {
    public:
        virtual void handle_event(SDL_Event event) = 0;
        virtual void update() = 0;
        virtual void render(sdl::Renderer &renderer) = 0;
        virtual ~Entity() = default;
    };

} // namespace automation::engine
