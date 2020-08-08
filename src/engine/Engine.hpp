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
        auto run() -> void;
        auto stop() -> void;

    private:
        auto handle_event(SDL_Event event) -> void;
        auto render(sdl::Renderer &renderer) -> void;

        auto handle_movement_event(SDL_Event event) -> bool;

        sdl::SDL m_sdl{};
        sdl::Window m_window{m_sdl};
        sdl::Renderer m_renderer{m_window};

        bool m_running = false;

        Manager m_manager;
    };

} // namespace automation::engine
