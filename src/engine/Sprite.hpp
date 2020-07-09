#pragma once

#include "Entity.hpp"
#include "Vector2d.hpp"

#include <filesystem>

namespace automation::engine
{

    class Sprite : public virtual Entity
    {
    public:
        Sprite(Vector2d posititon);
        virtual ~Sprite() = default;
        
        void render(sdl::Renderer &renderer) override;

    protected:
        std::filesystem::path sprite_path() const;

        Vector2d m_position;
    };

} // namespace automation::engine
