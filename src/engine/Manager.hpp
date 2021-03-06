#pragma once

#include "entities/Entity.hpp"

#include <memory>
#include <vector>

namespace automation::engine {

    class Manager : public Entity
    {
    public:
        void handle_event(SDL_Event event) override;
        void update() override;
        void render(sdl::Renderer &renderer) override;
        std::vector<std::unique_ptr<Entity>> m_entities;
    };

} // namespace automation::engine
