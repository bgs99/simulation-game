#pragma once

namespace automation::util
{
    class Vector2d
    {
    public:
        constexpr Vector2d()
            : x{0}, y{0}
        {
        }

        constexpr Vector2d(double x, double y)
            : x{x}, y{y}
        {
        }

        constexpr auto length() -> double
        {
            return std::sqrt(x * x + y * y);
        }

        constexpr auto normalize() -> Vector2d
        {
            return *this / length();
        }

        constexpr auto operator+=(Vector2d other) -> void
        {
            x += other.x;
            y += other.y;
        }

        constexpr auto operator-=(Vector2d other) -> void
        {
            x -= other.x;
            y -= other.y;
        }

        constexpr auto operator*=(double k) -> void
        {
            x *= k;
            y *= k;
        }

        constexpr auto operator/=(double k) -> void
        {
            x /= k;
            y /= k;
        }

        constexpr auto operator+(Vector2d other) -> Vector2d
        {
            return Vector2d{x + other.x, y + other.y};
        }

        constexpr auto operator-(Vector2d other) -> Vector2d
        {
            return Vector2d{x - other.x, y - other.y};
        }

        constexpr auto operator*(double k) -> Vector2d
        {
            return Vector2d{x * k, y * k};
        }

        constexpr auto operator/(double k) -> Vector2d
        {
            return Vector2d{x / k, y / k};
        }

        double x;
        double y;
    };

} // namespace automation::util
