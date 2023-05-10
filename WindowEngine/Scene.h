#pragma once

// ���漱�� ��� ��� ������ ������ �����ϰ� ���漱���� �Ѵ�.
class Object;

class Scene
{
private:
	// ������Ʈ Ŭ������ ��ӹ޴� Ŭ������ Object*�� ����ų�� �����Ƿ�
	// ������Ʈ�� �߰��ϴ� �����̱� ������ 32���� ������ ���� vecrtor ��ü�� �޸� ������ ���� �������� �ʴ´�.
	/// ��� ����
	vector<Object*> m_obj[(UINT)OBJECT_TYPE::END];
	wstring         m_name; // Scene �̸�
	void SetName(const wstring& _strName) { m_name = _strName; }
	const wstring& GetName() { return m_name; }

public:
	virtual void Start();
	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);

	virtual void Exit() = 0; // �ش� Scene�� ���Խ� ȣ��
	virtual void Enter() = 0; // �ش� Scene�� Ż�� �� ȣ��

public:

	const vector<Object*>& GetGroupObject(OBJECT_TYPE _type) { return m_obj[(UINT)_type]; }
	void AddObject(Object* _obj, OBJECT_TYPE _type) { m_obj[(UINT)_type].push_back(_obj); }
	void DeleteGroup(OBJECT_TYPE _target);
	void DeleteAll();

public:
	Scene();
	virtual~Scene();

};

