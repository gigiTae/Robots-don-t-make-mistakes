#include "pch.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_obj[i].size(); ++j)
		{
			// m_arrObj[i] 그룹 j 물체 삭제
			delete m_obj[i][j];
		}

	}
}


void Scene::Start()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_obj[i].size(); ++j)
		{
			m_obj[i][j]->Start();
		}

	}
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_obj[i].size(); ++j)
		{
			m_obj[i][j]->Update();
		}

	}
}

void Scene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_obj[i].size(); ++j)
		{
			m_obj[i][j]->Finalupdate();
		}

	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_obj[i].size(); ++j)
		{
			m_obj[i][j]->Render(_dc);
		}

	}
}

void Scene::DeleteGroup(OBJECT_TYPE _target)
{
   //	Safe_Delete_Vec<Object*>(m_arrObj[(UINT)_eTarget]);
}

void Scene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
		DeleteGroup((OBJECT_TYPE)i);
}

