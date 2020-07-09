#include "Vector2d.hpp"

#include <cmath>

namespace automation::engine
{

    Vector2d::Vector2d(double x, double y)
        : x{x}, y{y}
    {
    }

    double Vector2d::length()
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2d Vector2d::normalize()
    {
        return *this / length();
    }

    Vector2d Vector2d::operator+(Vector2d other)
    {
        return Vector2d{x + other.x, y + other.y};
    }

    Vector2d Vector2d::operator-(Vector2d other)
    {
        return Vector2d{x - other.x, y - other.y};
    }

    Vector2d Vector2d::operator*(double k)
    {
        return Vector2d{x * k, y * k};
    }

    Vector2d Vector2d::operator/(double k)
    {
        return Vector2d{x / k, y / k};
    }

} // namespace automation::engine
