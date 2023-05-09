#pragma once


/// <summary>
/// GDI 선택을 편리하게 해주는 클래스
/// </summary>
class SelectGDI
{

private:
	/// 멤버 변수
	HDC  m_hDC;
	HPEN m_hDefaultPen;
	HBRUSH m_hDefaultBrush;

public:

	/// 생성자
	SelectGDI(HDC _dc, PEN_TYPE _penType);
	SelectGDI(HDC _dc, BRUSH_TYPE _brushType);
	
	/// 소멸자
	~SelectGDI();
};

