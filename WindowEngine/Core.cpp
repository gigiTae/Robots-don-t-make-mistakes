
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

	// 해상도에 맞게 윈도우 크기 조정
	ChangeWindowSize(Vector2((float)_resolution.x, (float)_resolution.y), false);



	// Manager 초기화

	// TimgMgr::GetInst()->Init();
	// KeyMgr::GetInst()->Init();
	// PathMgr::GetInst()->Init();

	return S_OK; // 초기화 성공을 반환
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
	//           충돌 체크
	// ============================


	// ============================
	//           랜더링
	// ============================


	// ============================
	//        이벤트 지연 처리
	// ============================

}

void Core::ChangeWindowSize(Vector2 _resolution ,bool _menu)
{
	/*
	이 코드는 Windows API 함수를 사용하여 윈도우의 위치와 크기를 조정하는 코드입니다.

	 AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	 이 함수는 윈도우의 크기를 조정하기 위해 사용됩니다. 인자로 전달되는 rt는 RECT 구조체로, 윈도우의 클라이언트 영역을 나타냅니다.
	 WS_OVERLAPPEDWINDOW는 윈도우의 기본 스타일을 나타내며, 윈도우 프레임, 제목 표시줄, 크기 조절 막대, 메뉴, 경계선 등이 포함됩니다.
	 _bMenu는 윈도우에 메뉴가 있는지 여부를 나타내며, TRUE이면 메뉴가 있고, FALSE이면 메뉴가 없습니다. 이 함수는 윈도우의 설정 스타일에 맞는 크기를 계산하여 RECT 구조체를 업데이트합니다.

	 SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	 이 함수는 윈도우의 위치와 크기를 조정하는 함수입니다. 인자로 전달되는 m_hWnd는 윈도우 핸들입니다. 두 번째 인자는 윈도우를 조정할 때 기준이 될 창입니다.
	 nullptr이 전달되면 현재 윈도우를 기준으로 조정됩니다. 세 번째와 네 번째 인자는 윈도우가 표시될 좌표입니다. 다섯 번째와 여섯 번째 인자는 윈도우의 폭과 높이를 나타냅니다.
	 마지막 인자는 윈도우를 조정할 때 사용할 플래그 값입니다. 0을 전달하면 기본값을 사용합니다.

	 이 함수를 호출하면, 윈도우의 위치와 크기가 조정되며, 화면에 나타납니다. 조정된 윈도우의 크기는 앞서 호출한 AdjustWindowRect 함수로 계산한 윈도우의 크기와 일치합니다.
	*/

	RECT rt = { 0, 0, (long)_resolution.x, (long)_resolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _menu);

	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

}
