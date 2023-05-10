
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
	// 메인 윈도우 DC는 릴리즈
	ReleaseDC(m_hWnd, m_hDC); 

	// 생성한 brush pen 해제
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_pen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; ++i)
	{
		// 윈도우 기본브러쉬는 내가 삭제하지 않는다.
		if (i < 2)
			continue;

		DeleteObject(m_brush[i]);
	}
	
}

int Core::Init(HWND _hWnd, POINT _resolution)
{
	m_hWnd = _hWnd;
	m_resolution = _resolution;

	// 해상도에 맞게 윈도우 크기 조정
	ChangeWindowSize(Vector2((float)_resolution.x, (float)_resolution.y), false);


	// 자주 사용하는 펜과 브러쉬 생성
	CreateBrushPen();

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

void Core::CreateBrushPen()
{
	// 윈도우가 가지는 기본 브러쉬
	m_brush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_brush[(UINT)BRUSH_TYPE::BLACK] = (HBRUSH)GetStockObject(BLACK_BRUSH);
	// 여기부터 내가 추가해서 사용하는 브러쉬


	// 추가해서 사용하는 펜
	m_pen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_pen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_pen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

}
