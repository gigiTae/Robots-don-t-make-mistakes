#pragma once

class Core
{
	SINGLE(Core);

private:
	/// 멤버 변수
	HWND  m_hWnd;       // 메인 윈도우 핸들
	POINT m_resolution; // 메인 윈도우 해상도
	HDC   m_hDC;        // 메인 윈도우 Draw DC

	// 자주 사용하는 GDI
	HBRUSH m_brush[(UINT)BRUSH_TYPE::END];
	HPEN   m_pen[(UINT)PEN_TYPE::END];

public:

	/// 멤버 함수
	
	// 게임 시작시에 호출하는 함수
	int Init(HWND _hWnd, POINT _resolution);  
	// 게임 루프
	void Progress();
	// WindowSize 조정
	void ChangeWindowSize(Vector2 _resolution, bool _menu);

	HBRUSH GetBrush(BRUSH_TYPE _brushType) { return m_brush[(UINT)_brushType]; }
	HPEN GetPen(PEN_TYPE _penType) { return m_pen[(UINT)_penType]; }


private:
	void CreateBrushPen();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }

};

