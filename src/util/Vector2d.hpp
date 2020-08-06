#pragma once

namespace automation::util
{
    class Vector2d
    {
    public:
        Vector2d(double x, double y);

        Vector2d operator+(Vector2d other);
        Vector2d operator-(Vector2d other);
        Vector2d operator/(double k);
        Vector2d operator*(double k);

        double length();
        Vector2d normalize();

        double x;
        double y;
    };

} // namespace automation::util
