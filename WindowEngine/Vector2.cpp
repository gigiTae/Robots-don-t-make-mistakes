
#include "pch.h"
#include "Vector2.h"


// 정적멤버 변수 초기화
const Vector2 Vector2::UnitX{ 1.f,0.f };
const Vector2 Vector2::UnitY(0.f, 1.f);
const Vector2 Vector2::One(1.f, 1.f);
const Vector2 Vector2::Zero{ 0.f,0.f };

inline constexpr Vector2::Vector2(int _x, int _y)
	:x((float)_x)
	,y((float)_y)
{
}

inline constexpr Vector2::Vector2(float _x, float _y)
	:x(_x)
	,y(_y)
{
}

inline constexpr Vector2 Vector2::operator-() const
{
	return Vector2();
}

inline constexpr Vector2 Vector2::operator*(float _scalar) const
{
	return Vector2();
}

inline constexpr Vector2 Vector2::operator/(float _scalar) const
{
	return Vector2();
}

inline constexpr Vector2 Vector2::operator*(const Vector2& _other) const
{
	return Vector2();
}

inline constexpr Vector2 Vector2::operator+(const Vector2& _other) const
{
	return Vector2();
}

inline constexpr Vector2 Vector2::operator-(const Vector2& _other) const
{
	return Vector2();
}
