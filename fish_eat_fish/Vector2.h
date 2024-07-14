#pragma once

#include <cmath>

// 二维向量类，用double精确化
class Vector2
{
public:

	double x = 0;
	double y = 0;

public:

	Vector2(double x = 0, double y = 0);

	~Vector2() = default;

	void operator = (const Vector2& other);

	Vector2 operator + (const Vector2& other) const;

	void operator += (const Vector2& other);

	Vector2 operator - (const Vector2& other) const;

	void operator -= (const Vector2& other);

	double operator * (const Vector2& other) const;

	Vector2 operator * (double val) const;

	void operator *= (double val);

	void operator *= (const Vector2& other);

	//获取length长度
	double length();

	// normalize标准化（单位化）
	Vector2 normalize();

};

