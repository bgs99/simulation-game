#include "Human.hpp"

namespace fs = std::filesystem;

namespace automation::entities
{

    Human::Human(util::Vector2d position)
        : Sprite(position)
    {
    }

    fs::path Human::sprite_path() const
    {
        return fs::path{"face48.png"};
    }

    void Human::handle_event(SDL_Event event)
    {

    }

    void Human::update()
    {

    }

} // namespace automation::entities
