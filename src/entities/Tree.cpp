#include "Tree.hpp"

namespace fs = std::filesystem;

namespace automation::entities
{

    Tree::Tree(util::Vector2d position)
        : Sprite(position)
    {
    }

    fs::path Tree::sprite_path() const
    {
        return fs::path{"tree48.png"};
    }

    void Tree::handle_event(SDL_Event event)
    {

    }

    void Tree::update()
    {

    }

} // namespace automation::entities
