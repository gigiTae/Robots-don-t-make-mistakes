#pragma once



class Object
{

private:

	/// 멤버 변수
	//Vector2 m_pos; 
	//Vector2 m_scale;


public:
	/// 멤버 함수

	


public:
	virtual void Start() {};
	virtual void Update() = 0;
	virtual void Finalupdate();

	virtual void Render(HDC _dc);

	void RenderComponent(HDC _dc);

public:
	/// 생성자
	Object();

	/// 소멸자
	~Object();

};

