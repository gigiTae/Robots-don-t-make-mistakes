#pragma once



class Object
{

private:
	wstring m_name;

	Vector2 m_pos;
	Vector2 m_scale;

	bool m_alive;

public:
	/// 멤버 함수
	void SetPos(Vector2 _pos) { m_pos = _pos; }
	void SetScale(Vector2 _scale) { m_scale = _scale; }

	Vector2 GetPos() { return m_pos; }
	Vector2 GetScale() { return m_scale; }

	void SetName(const wstring& _name) { m_name = _name; }
	const wstring& GetName() { return m_name; }
	
	bool IsDead() { return !m_alive; }
	void SetDead() { m_alive = false; }

public:
	virtual void Start() {};
	virtual void Update() = 0;
	virtual void Finalupdate();
	virtual void Render(HDC _dc);

public:
	/// 생성자
	Object();

	/// 소멸자
	~Object();

};

