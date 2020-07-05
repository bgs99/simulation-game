#include "Manager.hpp"

namespace automation::engine
{

    void Manager::handle_event(SDL_Event event)
    {
        for (const auto &entity : m_entities)
        {
            entity->handle_event(event);
        }
    }

    void Manager::update()
    {
        for (const auto &entity : m_entities)
        {
            entity->update();
        }
    }

    void Manager::render(sdl::RendererWrapper &renderer)
    {
        for (const auto &entity : m_entities)
        {
            entity->render(renderer);
        }
    }

} // namespace automation::engine
