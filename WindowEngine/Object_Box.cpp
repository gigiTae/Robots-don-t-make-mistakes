#include "pch.h"
#include "Object_Box.h"
#include "KeyMgr.h"
#include "SelectGDI.h"

Object_Box::Object_Box()
{
}

Object_Box::~Object_Box()
{
}

void Object_Box::Update()
{
	// 부모클래스의 멤버함수또한 함수를 통해서 접근한다.
	Vector2 pos = GetPos();

	if (KeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		pos.x--;
	}

	if (KeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		pos.x++;
	}

	// 부모클래스이 멤버함수를 함수를 통해서 값을 바꾼다.
	SetPos(pos);
}

void Object_Box::Render(HDC _dc)
{
	// GDI 선택 브러쉬 타입, 펜타입을 자유자재로 설정가능
	SelectGDI gdi = SelectGDI(_dc, PEN_TYPE::RED);

	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	// 랜더링
	Rectangle(_dc
		, (int)(pos.x - scale.x / 2.f)
		, (int)(pos.y - scale.y / 2.f)
		, (int)(pos.x + scale.x / 2.f)
		, (int)(pos.y + scale.y / 2.f));


}
