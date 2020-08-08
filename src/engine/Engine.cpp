#include "Engine.hpp"

#include "entities/Human.hpp"
#include "entities/Tree.hpp"

namespace automation::engine
{

    void Engine::stop()
    {
        m_running = false;
    }

    void Engine::run()
    {
        m_running = true;

        m_manager.m_entities.emplace_back(
            static_cast<Entity *>(
                new entities::Human{util::Vector2d{48, 48}}));

        m_manager.m_entities.emplace_back(
            static_cast<Entity *>(
                new entities::Tree{util::Vector2d{48 * 3, 48 * 3}}));

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

    auto Engine::handle_movement_event(SDL_Event event) -> bool
    {
        switch (event.key.keysym.sym)
        {
        case SDL_KeyCode::SDLK_UP:
            m_renderer.move({0, -48});
            return true;
        case SDL_KeyCode::SDLK_DOWN:
            m_renderer.move({0, 48});
            return true;
        case SDL_KeyCode::SDLK_LEFT:
            m_renderer.move({-48, 0});
            return true;
        case SDL_KeyCode::SDLK_RIGHT:
            m_renderer.move({48, 0});
            return true;
        default:
            return false;
        }
    }

    auto Engine::handle_event(SDL_Event event) -> void
    {
        switch (event.type)
        {
        case SDL_QUIT:
            stop();
            break;
        case SDL_KEYDOWN:
            if (!handle_movement_event(event))
            {
                m_manager.handle_event(event);
            }
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
