#pragma once

#include "Sprite.hpp"

namespace automation::entities
{

    class Human : public engine::Sprite
    {
    public:
        Human(util::Vector2d position);

    private:
        std::filesystem::path sprite_path() const override;

        void handle_event(SDL_Event event) override;
        void update() override;
    };

} // namespace automation::entities
