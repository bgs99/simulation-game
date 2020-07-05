#pragma once

#include "Entity.hpp"

#include <memory>
#include <vector>

namespace automation::engine {

    class Manager : public Entity
    {
    public:
        void handle_event(SDL_Event event) override;
        void update() override;
        void render(sdl::RendererWrapper &renderer) override;
        std::vector<std::unique_ptr<Entity>> m_entities;
    };

} // namespace automation::engine
