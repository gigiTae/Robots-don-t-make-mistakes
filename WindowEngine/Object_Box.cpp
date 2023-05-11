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
	// �θ�Ŭ������ ����Լ����� �Լ��� ���ؼ� �����Ѵ�.
	Vector2 pos = GetPos();

	if (KeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		pos.x--;
	}

	if (KeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		pos.x++;
	}

	// �θ�Ŭ������ ����Լ��� �Լ��� ���ؼ� ���� �ٲ۴�.
	SetPos(pos);
}

void Object_Box::Render(HDC _dc)
{
	// GDI ���� �귯�� Ÿ��, ��Ÿ���� ��������� ��������
	SelectGDI gdi = SelectGDI(_dc, PEN_TYPE::RED);

	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	// ������
	Rectangle(_dc
		, (int)(pos.x - scale.x / 2.f)
		, (int)(pos.y - scale.y / 2.f)
		, (int)(pos.x + scale.x / 2.f)
		, (int)(pos.y + scale.y / 2.f));


}
