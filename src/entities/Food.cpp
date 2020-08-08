#include "Food.hpp"

namespace fs = std::filesystem;

namespace automation::entities
{

    Food::Food(util::Vector2d position)
        : Sprite(position)
    {
    }

    fs::path Food::sprite_path() const
    {
        return fs::path{"food48.png"};
    }

    void Food::handle_event(SDL_Event event)
    {

    }

    void Food::update()
    {

    }

} // namespace automation::entities
