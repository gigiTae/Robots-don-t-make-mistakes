#pragma once

class Core
{
	SINGLE(Core);

private:
	/// ��� ����
	HWND  m_hWnd;       // ���� ������ �ڵ�
	POINT m_resolution; // ���� ������ �ػ�
	HDC   m_hDC;        // ���� ������ Draw DC

	// ���� ����ϴ� GDI
	HBRUSH m_brush[(UINT)BRUSH_TYPE::END];
	HPEN   m_pen[(UINT)PEN_TYPE::END];

public:

	/// ��� �Լ�
	
	// ���� ���۽ÿ� ȣ���ϴ� �Լ�
	int Init(HWND _hWnd, POINT _resolution);  
	// ���� ����
	void Progress();
	// WindowSize ����
	void ChangeWindowSize(Vector2 _resolution, bool _menu);

	HBRUSH GetBrush(BRUSH_TYPE _brushType) { return m_brush[(UINT)_brushType]; }
	HPEN GetPen(PEN_TYPE _penType) { return m_pen[(UINT)_penType]; }


private:
	void CreateBrushPen();

public:
	HWND GetMainHwnd() { return m_hWnd; }

};

