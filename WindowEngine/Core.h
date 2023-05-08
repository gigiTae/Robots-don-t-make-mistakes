#pragma once

class Core
{
	SINGLE(Core);

private:
	HWND  m_hWnd;       // 메인 윈도우 핸들
	POINT m_Resolution; // 메인 윈도우 해상도
	HDC   m_hDC;        // 메인 윈도우 Draw DC



public:

	// 게임 시작시에 호출하는 함수
	int Init(HWND _hWnd, POINT _resolution);  
	
	// 게임 루프
	void Progress();



};

