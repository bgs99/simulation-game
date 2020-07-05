#include "engine/Engine.hpp"

#include <iostream>

int main()
{
    using namespace automation;

    engine::Engine engine{};

    engine.run();

    return 0;
}