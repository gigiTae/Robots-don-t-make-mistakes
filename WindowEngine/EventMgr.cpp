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
    // 이전 프레임에서 등록해둔 Dead Object 들을 삭제한다.
    // ===================================================

	for (size_t i = 0; i < m_deadObj.size(); ++i)
	{
		// 죽은 오브젝트 메모리 해제
		delete m_deadObj[i];
	}

	// 데드 배열 클리어
	m_deadObj.clear();

	// ============
	//  Event 처리
	// ============
	for (size_t i = 0; i < m_event.size(); ++i)
	{
		// 이번 프레임에서 발생한 이벤트들을 처리
		ExecuteEvent(m_event[i]);
	}

	// 처리한 이벤트들 클리어
	m_event.clear();
}

void EventMgr::ExecuteEvent(const Event& _event)
{
	switch (_event.type)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : 오브젝트 주소
		// wParam : 오브젝트 타입
		Object* obj = (Object*)_event.lParam;
		OBJECT_TYPE type = (OBJECT_TYPE)_event.wParam;

		SceneMgr::GetInst()->GetCurScene()->AddObject(obj, type);
	}
		break;

	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : 오브젝트 주소
		Object* obj = (Object*)_event.lParam;

		// 오브젝트에 대한 예외처리를 위해서 dead상태로 만든다.
		if (!obj->IsDead())
		{
			obj->SetDead();
			m_deadObj.push_back(obj);
		}
	}
	
		break;

	case EVENT_TYPE::CHANGE_SCENE:

		// lParam : 다음 씬 타입
		
		// 현재 가지고 있는 이벤트들 모두 삭제

		// Scene 변경
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
