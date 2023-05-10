#pragma once

// 전방선언 헤더 헤더 끼리의 참조를 방지하고 전방선언을 한다.
class Object;

class Scene
{
private:
	// 오브젝트 클래스를 상속받는 클래스는 Object*로 가리킬수 있으므로
	// 오브젝트는 추가하는 형식이기 때문에 32개의 공간을 만들어도 vecrtor 자체는 메모리 공간을 별로 차지하지 않는다.
	/// 멤버 변수
	vector<Object*> m_obj[(UINT)OBJECT_TYPE::END];
	wstring         m_name; // Scene 이름
	void SetName(const wstring& _strName) { m_name = _strName; }
	const wstring& GetName() { return m_name; }

public:
	virtual void Start();
	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);

	virtual void Exit() = 0; // 해당 Scene에 진입시 호출
	virtual void Enter() = 0; // 해당 Scene을 탈출 시 호출

public:

	const vector<Object*>& GetGroupObject(OBJECT_TYPE _type) { return m_obj[(UINT)_type]; }
	void AddObject(Object* _obj, OBJECT_TYPE _type) { m_obj[(UINT)_type].push_back(_obj); }
	void DeleteGroup(OBJECT_TYPE _target);
	void DeleteAll();

public:
	Scene();
	virtual~Scene();

};

