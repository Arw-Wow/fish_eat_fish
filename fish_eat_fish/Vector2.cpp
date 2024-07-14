#include "Vector2.h"

Vector2::Vector2(double x, double y) : x(x), y(y) { }

void Vector2::operator=(const Vector2& other)
{
    x = other.x;
    y = other.y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

void Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

void Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
}

double Vector2::operator*(const Vector2& other) const
{
    return x * other.x + y * other.y;
}

Vector2 Vector2::operator*(double val) const
{
    return Vector2(x * val, y * val);
}

void Vector2::operator*=(double val)
{
    x *= val;
    y *= val;
}

void Vector2::operator*=(const Vector2& other)
{
    x *= other.x;
    y *= other.y;
}

//获取length长度

double Vector2::length()
{
    return sqrt(x * x + y * y);
}

// normalize标准化（单位化）

Vector2 Vector2::normalize()
{
    double len = length();

    if (len == 0)
        return Vector2(0, 0);

    return Vector2(x / len, y / len);
}
