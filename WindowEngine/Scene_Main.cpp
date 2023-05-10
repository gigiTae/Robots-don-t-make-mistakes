#include "pch.h"
#include "Scene_Main.h"
#include "Object_Box.h"

Scene_Main::Scene_Main()
{
}

Scene_Main::~Scene_Main()
{
}

void Scene_Main::Exit()
{
	DeleteAll();

}

void Scene_Main::Enter()
{
	// 오브젝트 추가 예시
	Object_Box* box = new Object_Box;
	box->SetPos(Vector2(100.f,100.f));
	box->SetScale(Vector2(100.f, 100.f));
	
	AddObject(box, OBJECT_TYPE::PLAYER);

}
