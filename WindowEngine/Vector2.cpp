
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
{}

inline constexpr Vector2::Vector2(float _x, float _y)
	:x(_x)
	,y(_y)
{}

inline constexpr Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

inline constexpr Vector2 Vector2::operator*(float _scalar) const
{
	return Vector2(x * _scalar, y * _scalar);
}

inline constexpr Vector2 Vector2::operator/(float _scalar) const
{
	// 0으로 나누는 경우
	assert(_scalar);

	return Vector2(x / _scalar, y / _scalar);
}

inline constexpr Vector2 Vector2::operator*(const Vector2& _other) const
{
	return Vector2(x * _other.x, y * _other.y);
}

inline constexpr Vector2 Vector2::operator+(const Vector2& _other) const
{
	return Vector2(x + _other.x, y + _other.y);
}

inline constexpr Vector2 Vector2::operator-(const Vector2& _other) const
{
	return Vector2(x - _other.x, y - _other.y);
}

inline constexpr Vector2& Vector2::operator*=(float _scale)
{
	x *= _scale;
	y *= _scale;

	return *this;
}

inline constexpr Vector2& Vector2::operator/=(float _scale)
{
	x /= _scale;
	y /= _scale;

	return *this;
}

inline constexpr Vector2& Vector2::operator+=(const Vector2& _other)
{
	x += _other.x;
	y += _other.y;

	return *this;
}

inline constexpr Vector2& Vector2::operator-=(const Vector2& _other)
{
	x -= _other.x;
	y -= _other.y;

	return *this;
}

inline float Vector2::Size() const
{  
	return sqrtf(SizeSquared());
}

inline constexpr float Vector2::SizeSquared() const
{
	return x * x + y * y;
}


Vector2 Vector2::GetNormalize() const
{
	float squarSum = SizeSquared(); 
	if (squarSum == 1.f)
	{
		return *this;
	}
	else if (squarSum == 0.f)
	{
		return Vector2::Zero;
	}

	// 고속 역 제곱근 공식을 사용하면 빠른 연산이 가능하지만 아직 어려움
	
	float invLength = 1 / sqrtf(squarSum);

	return Vector2(x, y) * invLength;
}

inline float Vector2::Angle() const
{
	return atan2f(y, x);
}

void Vector2::Nomalize()
{
	*this = GetNormalize();
}

inline Vector2 Vector2::ToPolarCoordinate() const
{
	return Vector2(Size(), Angle());
}

inline Vector2 Vector2::ToCartesianCoordinate() const
{
	// 극좌표계에서는 x는 반지름 y는 각(rad)으로 활용
	float sinValue = sin(y);
	float cosValue = cos(y);

	return Vector2(x * sinValue, x * cosValue);
}

string Vector2::ToString() const
{
	char result[64];
	std::snprintf(result, sizeof(result), "(%.3f, %.3f)", x, y);
	return result;
}

