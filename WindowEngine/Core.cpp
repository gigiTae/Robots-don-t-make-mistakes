
#include "pch.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimgMgr.h"

Core::Core()
	:m_hWnd(nullptr)
	,m_resolution{}
	,m_hDC(nullptr)
	,m_pen{}
	,m_brush{}
{}

Core::~Core()
{
	// ���� ������ DC�� ������
	ReleaseDC(m_hWnd, m_hDC); 

	// ������ brush pen ����
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_pen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; ++i)
	{
		// ������ �⺻�귯���� ���� �������� �ʴ´�.
		if (i < 2)
			continue;

		DeleteObject(m_brush[i]);
	}
	
}

int Core::Init(HWND _hWnd, POINT _resolution)
{
	m_hWnd = _hWnd;
	m_resolution = _resolution;

	// �ػ󵵿� �°� ������ ũ�� ����
	ChangeWindowSize(Vector2((float)_resolution.x, (float)_resolution.y), false);


	// ���� ����ϴ� ��� �귯�� ����
	CreateBrushPen();

	// Manager �ʱ�ȭ

	// TimgMgr::GetInst()->Init();
	// KeyMgr::GetInst()->Init();
	// PathMgr::GetInst()->Init();

	return S_OK; // �ʱ�ȭ ������ ��ȯ
}

void Core::Progress()
{
	// ============================
	//        Manager Update
    // ============================


	// ============================
	//        Scene Update
	// ============================


	// ============================
	//           �浹 üũ
	// ============================


	// ============================
	//           ������
	// ============================


	// ============================
	//        �̺�Ʈ ���� ó��
	// ============================

}

void Core::ChangeWindowSize(Vector2 _resolution ,bool _menu)
{
	/*
	�� �ڵ�� Windows API �Լ��� ����Ͽ� �������� ��ġ�� ũ�⸦ �����ϴ� �ڵ��Դϴ�.

	 AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	 �� �Լ��� �������� ũ�⸦ �����ϱ� ���� ���˴ϴ�. ���ڷ� ���޵Ǵ� rt�� RECT ����ü��, �������� Ŭ���̾�Ʈ ������ ��Ÿ���ϴ�.
	 WS_OVERLAPPEDWINDOW�� �������� �⺻ ��Ÿ���� ��Ÿ����, ������ ������, ���� ǥ����, ũ�� ���� ����, �޴�, ��輱 ���� ���Ե˴ϴ�.
	 _bMenu�� �����쿡 �޴��� �ִ��� ���θ� ��Ÿ����, TRUE�̸� �޴��� �ְ�, FALSE�̸� �޴��� �����ϴ�. �� �Լ��� �������� ���� ��Ÿ�Ͽ� �´� ũ�⸦ ����Ͽ� RECT ����ü�� ������Ʈ�մϴ�.

	 SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	 �� �Լ��� �������� ��ġ�� ũ�⸦ �����ϴ� �Լ��Դϴ�. ���ڷ� ���޵Ǵ� m_hWnd�� ������ �ڵ��Դϴ�. �� ��° ���ڴ� �����츦 ������ �� ������ �� â�Դϴ�.
	 nullptr�� ���޵Ǹ� ���� �����츦 �������� �����˴ϴ�. �� ��°�� �� ��° ���ڴ� �����찡 ǥ�õ� ��ǥ�Դϴ�. �ټ� ��°�� ���� ��° ���ڴ� �������� ���� ���̸� ��Ÿ���ϴ�.
	 ������ ���ڴ� �����츦 ������ �� ����� �÷��� ���Դϴ�. 0�� �����ϸ� �⺻���� ����մϴ�.

	 �� �Լ��� ȣ���ϸ�, �������� ��ġ�� ũ�Ⱑ �����Ǹ�, ȭ�鿡 ��Ÿ���ϴ�. ������ �������� ũ��� �ռ� ȣ���� AdjustWindowRect �Լ��� ����� �������� ũ��� ��ġ�մϴ�.
	*/

	RECT rt = { 0, 0, (long)_resolution.x, (long)_resolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _menu);

	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

}

void Core::CreateBrushPen()
{
	// �����찡 ������ �⺻ �귯��
	m_brush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_brush[(UINT)BRUSH_TYPE::BLACK] = (HBRUSH)GetStockObject(BLACK_BRUSH);
	// ������� ���� �߰��ؼ� ����ϴ� �귯��


	// �߰��ؼ� ����ϴ� ��
	m_pen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_pen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_pen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

}
