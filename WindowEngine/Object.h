#pragma once



class Object
{

private:

	/// ��� ����
	//Vector2 m_pos; 
	//Vector2 m_scale;


public:
	/// ��� �Լ�

	


public:
	virtual void Start() {};
	virtual void Update() = 0;
	virtual void Finalupdate();

	virtual void Render(HDC _dc);

	void RenderComponent(HDC _dc);

public:
	/// ������
	Object();

	/// �Ҹ���
	~Object();

};

