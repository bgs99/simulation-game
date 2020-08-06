#include "Sprite.hpp"

namespace automation::engine
{

    Sprite::Sprite(util::Vector2d position)
        : m_position{position}
    {
    }

    void Sprite::render(sdl::Renderer &renderer)
    {
        renderer.render_texture(sprite_path(), m_position);
    }

} // namespace automation::engine
