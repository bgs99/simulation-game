#include "Engine.hpp"

namespace automation::engine
{

    void Engine::stop()
    {
        m_running = false;
    }

    void Engine::run()
    {
        m_running = true;
        while (m_running)
        {
            for (const auto event : sdl::get_events())
            {
                handle_event(event);
            }
            m_manager.update();
            render(m_renderer);
        }
    }

    void Engine::handle_event(SDL_Event event)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            stop();
            break;

        default:
            m_manager.handle_event(event);
            break;
        }
    }

    void Engine::render(sdl::Renderer &renderer)
    {
        renderer.set_color(100, 200, 100);

        renderer.clear();

        m_manager.render(renderer);

        renderer.present();
    }

} // namespace automation::engine
