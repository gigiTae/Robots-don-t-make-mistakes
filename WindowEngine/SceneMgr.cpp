#include "pch.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_Main.h"

SceneMgr::SceneMgr()
	:m_curScene(nullptr)
	,m_scene{}
{}

SceneMgr::~SceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_scene[i])
			delete m_scene[i];
	}
}

void SceneMgr::Init()
{
	// Scene ����
	m_scene[(UINT)SCENE_TYPE::MAIN] = new Scene_Main;


	// Start Scene -> ��ŸƮ�� ����
	m_curScene = m_scene[(UINT)SCENE_TYPE::MAIN];

	m_curScene->Enter();
}

void SceneMgr::Update()
{
	m_curScene->Update();
}

void SceneMgr::FinalUpdate()
{
	m_curScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_curScene->Render(_dc);
}

void SceneMgr::ChangeScene(SCENE_TYPE _next)
{
	// ����� ������ Exit ȣ��
	m_curScene->Exit();

	// ������ ����
	m_curScene = m_scene[(UINT)_next];

	// �������� ���� �����Լ� ȣ��
	m_curScene->Enter();
}
