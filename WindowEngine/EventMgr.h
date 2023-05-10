#pragma once

class Object;

struct Event
{
	EVENT_TYPE type;
	DWORD_PTR  lParam;
	DWORD_PTR  wParam;
};

class EventMgr
{
	SINGLE(EventMgr);

private:
	vector<Event> m_event;
	vector<Object*> m_deadObj;

public:
	void Update();

	void ExcuteEvent(const Event& _event);

	void CreateObject(Object* _obj, OBJECT_TYPE _type);
	void DeleteObject(Object* _obj);
	void ChangeScene(SCENE_TYPE _type);

	void AddEvent(const Event& _event) { m_event.push_back(_event); }
};

