#pragma once

namespace automation::util
{
    class Vector2d
    {
    public:
        Vector2d();
        Vector2d(double x, double y);

        auto operator+=(Vector2d other) -> void;
        auto operator-=(Vector2d other) -> void;
        auto operator/=(double k) -> void;
        auto operator*=(double k) -> void;
        auto operator+(Vector2d other) -> Vector2d;
        auto operator-(Vector2d other) -> Vector2d;
        auto operator/(double k) -> Vector2d;
        auto operator*(double k) -> Vector2d;

        auto length() -> double;
        auto normalize() -> Vector2d;

        double x;
        double y;
    };

} // namespace automation::util
