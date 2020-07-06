#include "detail.hpp"

namespace automation::sdl::detail
{
    template <>
    bool rv_fail<int>(int arg)
    {
        return arg < 0;
    }

} // namespace automation::sdl::detail
