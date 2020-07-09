#pragma once

#include "sdl/Events.hpp"
#include "sdl/Renderer.hpp"

namespace automation::engine
{

    class Engine;

    class Entity
    {
    public:
        Entity(Engine & engine);
        virtual void handle_event(SDL_Event event) = 0;
        virtual void update() = 0;
        virtual void render(sdl::Renderer &renderer) = 0;
        virtual ~Entity() = default;

    protected:
        Engine & m_engine;
    };

} // namespace automation::engine
