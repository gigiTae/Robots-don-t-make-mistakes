#pragma once



struct Vector2
{
public:
	/// 생성자
	inline Vector2() = default;
	inline explicit constexpr Vector2(int _x, int _y);
	inline explicit constexpr Vector2(float _x, float _y);

	/// 연산자
	inline constexpr Vector2 operator-() const;
	inline constexpr Vector2 operator*(float _scalar) const;
	inline constexpr Vector2 operator/(float _scalar) const;
	inline constexpr Vector2 operator*(const Vector2& _other) const;
	inline constexpr Vector2 operator+(const Vector2& _other) const;
	inline constexpr Vector2 operator-(const Vector2& _other) const;
	inline constexpr Vector2& operator*=(float _scale);
	inline constexpr Vector2& operator/=(float _scale);
	inline constexpr Vector2& operator+=(const Vector2& _other);
	inline constexpr Vector2& operator-=(const Vector2& _other);


	/// 멤버 함수

	// 루트 제곱근
	inline float Size() const;

	// 제곱근 반환
	inline constexpr float SizeSquared() const; 
	
	// 벡터 정규화
	void Nomalize();
	[[nodiscard]] Vector2 GetNormalize() const;

	// 반환값은 radian
	inline float Angle() const;

	// 직교좌표계 -> 극좌표계 변환
	inline Vector2 ToPolarCoordinate() const;

	// 극좌표계 -> 직교 좌표계 변환
	inline Vector2 ToCartesianCoordinate() const;

	string ToString() const;

	/// 정적멤버 변수
	static const Vector2 UnitX; // 표준기저벡터
	static const Vector2 UnitY; // 표준기저벡터
	static const Vector2 One;   
	static const Vector2 Zero;   
	static constexpr int Dimension = 2;


	/// 멤버 변수
	float x, y;



};