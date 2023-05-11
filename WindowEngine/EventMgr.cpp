#include "pch.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Object.h"

EventMgr::EventMgr()
	:m_event{}
	,m_deadObj{}
{}

EventMgr::~EventMgr()
{}

void EventMgr::Update()
{
	// ===================================================
    // ���� �����ӿ��� ����ص� Dead Object ���� �����Ѵ�.
    // ===================================================

	for (size_t i = 0; i < m_deadObj.size(); ++i)
	{
		// ���� ������Ʈ �޸� ����
		delete m_deadObj[i];
	}

	// ���� �迭 Ŭ����
	m_deadObj.clear();

	// ============
	//  Event ó��
	// ============
	for (size_t i = 0; i < m_event.size(); ++i)
	{
		// �̹� �����ӿ��� �߻��� �̺�Ʈ���� ó��
		ExecuteEvent(m_event[i]);
	}

	// ó���� �̺�Ʈ�� Ŭ����
	m_event.clear();
}

void EventMgr::ExecuteEvent(const Event& _event)
{
	switch (_event.type)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : ������Ʈ �ּ�
		// wParam : ������Ʈ Ÿ��
		Object* obj = (Object*)_event.lParam;
		OBJECT_TYPE type = (OBJECT_TYPE)_event.wParam;

		SceneMgr::GetInst()->GetCurScene()->AddObject(obj, type);
	}
		break;

	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : ������Ʈ �ּ�
		Object* obj = (Object*)_event.lParam;

		// ������Ʈ�� ���� ����ó���� ���ؼ� dead���·� �����.
		if (!obj->IsDead())
		{
			obj->SetDead();
			m_deadObj.push_back(obj);
		}
	}
	
		break;

	case EVENT_TYPE::CHANGE_SCENE:

		// lParam : ���� �� Ÿ��
		
		// ���� ������ �ִ� �̺�Ʈ�� ��� ����

		// Scene ����
		SceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_event.lParam);

		break;
	}
}

void EventMgr::CreateObject(Object* _obj, OBJECT_TYPE _type)
{
	Event evn = {};
	evn.type = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_obj;
	evn.wParam = (DWORD_PTR)_type;

	AddEvent(evn);
}

void EventMgr::DeleteObject(Object* _obj)
{
	Event evn = {};
	evn.type = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_obj;

	AddEvent(evn);
}

void EventMgr::ChangeScene(SCENE_TYPE _type)
{
	Event evn = {};
	evn.type = EVENT_TYPE::CHANGE_SCENE;
	evn.lParam = (DWORD_PTR)_type;

	AddEvent(evn);
}
