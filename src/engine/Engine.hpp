#pragma once

#include "Entity.hpp"
#include "Manager.hpp"

#include "sdl/SDLWrappers.hpp"

namespace automation::engine
{

    class Engine : public virtual Entity
    {
    public:
        Engine() = default;
        void run();
        void stop();

    private:
        void handle_event(SDL_Event event) override;
        void update() override;
        void render(sdl::RendererWrapper &renderer) override;

        sdl::SDLWrapper m_sdl{};
        sdl::WindowWrapper m_window{m_sdl};
        sdl::RendererWrapper m_renderer{m_window};

        bool m_running = false;

        Manager m_manager;
    };

} // namespace automation::engine
