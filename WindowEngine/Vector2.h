#pragma once



struct Vector2
{
public:
	/// ������
	inline Vector2() = default;
	inline explicit constexpr Vector2(int _x, int _y);
	inline explicit constexpr Vector2(float _x, float _y);

	/// ������
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


	/// ��� �Լ�

	// ��Ʈ ������
	inline float Size() const;

	// ������ ��ȯ
	inline constexpr float SizeSquared() const; 
	
	// ���� ����ȭ
	void Nomalize();
	[[nodiscard]] Vector2 GetNormalize() const;

	// ��ȯ���� radian
	inline float Angle() const;

	// ������ǥ�� -> ����ǥ�� ��ȯ
	inline Vector2 ToPolarCoordinate() const;

	// ����ǥ�� -> ���� ��ǥ�� ��ȯ
	inline Vector2 ToCartesianCoordinate() const;

	string ToString() const;

	/// ������� ����
	static const Vector2 UnitX; // ǥ�ر�������
	static const Vector2 UnitY; // ǥ�ر�������
	static const Vector2 One;   
	static const Vector2 Zero;   
	static constexpr int Dimension = 2;


	/// ��� ����
	float x, y;



};