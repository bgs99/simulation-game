#pragma once

#include "Manager.hpp"

#include "sdl/SDL.hpp"
#include "sdl/Window.hpp"
#include "sdl/Renderer.hpp"

namespace automation::engine
{

    class Engine
    {
    public:
        Engine() = default;
        void run();
        void stop();

    private:
        void handle_event(SDL_Event event);
        void render(sdl::Renderer &renderer);

        sdl::SDL m_sdl{};
        sdl::Window m_window{m_sdl};
        sdl::Renderer m_renderer{m_window};

        bool m_running = false;

        Manager m_manager;
    };

} // namespace automation::engine
