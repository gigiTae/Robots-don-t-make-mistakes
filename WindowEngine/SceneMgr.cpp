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
	// Scene 생성
	m_scene[(UINT)SCENE_TYPE::MAIN] = new Scene_Main;


	// Start Scene -> 스타트씬 지정
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
	// 현재씬 나가서 Exit 호출
	m_curScene->Exit();

	// 다음씬 지정
	m_curScene = m_scene[(UINT)_next];

	// 다음씬에 대한 엔터함수 호출
	m_curScene->Enter();
}
