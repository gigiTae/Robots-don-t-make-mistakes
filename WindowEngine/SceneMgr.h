#pragma once

class Scene;

class SceneMgr
{
	SINGLE(SceneMgr);

private:
	Scene* m_scene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	Scene* m_curScene;                       // ���� ��

public:
	void Init();
	void Update();
	void FinalUpdate();

	void Render(HDC _dc);

	Scene* GetCurScene() { return m_curScene; }

	void ChangeScene(SCENE_TYPE _next);

};

