
#include "pch.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimgMgr.h"

Core::Core()
	:m_hWnd(nullptr)
	,m_resolution{}
	,m_hDC(nullptr)
{}

Core::~Core()
{

}

int Core::Init(HWND _hWnd, POINT _resolution)
{
	m_hWnd = _hWnd;
	m_resolution = _resolution;

	// �ػ󵵿� �°� ������ ũ�� ����
	ChangeWindowSize(Vector2((float)_resolution.x, (float)_resolution.y), false);



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
