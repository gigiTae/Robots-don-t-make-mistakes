
#include "pch.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimgMgr.h"

int Core::Init(HWND _hWnd, POINT _resolution)
{
	m_hWnd = _hWnd;
	m_Resolution = _resolution;

	// 해상도에 맞게 윈도우 크기 조정


	// Manager 초기화

	// TimgMgr::GetInst()->Init();
	// KeyMgr::GetInst()->Init();



	return S_OK; // 초기화 성공을 반환
}

void Core::Progress()
{
}
