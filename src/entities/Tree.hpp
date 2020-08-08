#pragma once

#include "engine/Sprite.hpp"

namespace automation::entities
{

    class Tree : public engine::Sprite
    {
    public:
        Tree(util::Vector2d position);

    private:
        std::filesystem::path sprite_path() const override;

        void handle_event(SDL_Event event) override;
        void update() override;
    };

} // namespace automation::entities
