#include "Entity.hpp"

#include "Engine.hpp"

namespace automation::engine
{
    Entity::Entity(Engine &engine)
        : m_engine{engine}
    {
    }

} // namespace automation::engine
