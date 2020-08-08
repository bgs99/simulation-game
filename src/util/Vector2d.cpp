#include "Vector2d.hpp"

#include <cmath>

namespace automation::util
{

    Vector2d::Vector2d()
        : x{0}, y{0}
    {
    }

    Vector2d::Vector2d(double x, double y)
        : x{x}, y{y}
    {
    }

    auto Vector2d::length() -> double
    {
        return std::sqrt(x * x + y * y);
    }

    auto Vector2d::normalize() -> Vector2d
    {
        return *this / length();
    }

    auto Vector2d::operator+=(Vector2d other) -> void
    {
        x += other.x;
        y += other.y;
    }

    auto Vector2d::operator-=(Vector2d other) -> void
    {
        x -= other.x;
        y -= other.y;
    }

    auto Vector2d::operator*=(double k) -> void
    {
        x *= k;
        y *= k;
    }

    auto Vector2d::operator/=(double k) -> void
    {
        x /= k;
        y /= k;
    }

    auto Vector2d::operator+(Vector2d other) -> Vector2d
    {
        return Vector2d{x + other.x, y + other.y};
    }

    auto Vector2d::operator-(Vector2d other) -> Vector2d
    {
        return Vector2d{x - other.x, y - other.y};
    }

    auto Vector2d::operator*(double k) -> Vector2d
    {
        return Vector2d{x * k, y * k};
    }

    auto Vector2d::operator/(double k) -> Vector2d
    {
        return Vector2d{x / k, y / k};
    }

} // namespace automation::util
