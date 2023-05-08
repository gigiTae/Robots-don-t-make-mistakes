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
	

	/// 멤버 함수
	
	// 사이즈 반환 
	inline float Size() const;

	// 제곱근 반환
	inline constexpr float SizeSquared() const; // 제곱근 
	
	// 벡터 정규화
	void Nomalize();
	[[nodiscard]] Vector2 GetNomalize() const;


	/// 정적멤버 변수
	static const Vector2 UnitX; // 표준기저벡터
	static const Vector2 UnitY; // 표준기저벡터
	static const Vector2 One;   
	static const Vector2 Zero;   
	static constexpr int Dimension = 2;

	/// 멤버 변수
	union
	{
		struct
		{
			float x, y;
		};

		array<float, Dimension> Scalars;
	};

};