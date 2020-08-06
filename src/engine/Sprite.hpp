#pragma once

#include "Entity.hpp"

#include "util/Vector2d.hpp"

#include <filesystem>

namespace automation::engine
{

    class Sprite : public virtual Entity
    {
    public:
        Sprite(util::Vector2d posititon);
        virtual ~Sprite() = default;
        
        void render(sdl::Renderer &renderer) override;

    protected:
        virtual std::filesystem::path sprite_path() const = 0;

        util::Vector2d m_position;
    };

} // namespace automation::engine
