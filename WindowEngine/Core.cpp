
#include "pch.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimgMgr.h"

int Core::Init(HWND _hWnd, POINT _resolution)
{
	m_hWnd = _hWnd;
	m_Resolution = _resolution;

	// �ػ󵵿� �°� ������ ũ�� ����


	// Manager �ʱ�ȭ

	// TimgMgr::GetInst()->Init();
	// KeyMgr::GetInst()->Init();



	return S_OK; // �ʱ�ȭ ������ ��ȯ
}

void Core::Progress()
{
}
