#pragma once


/// <summary>
/// GDI ������ ���ϰ� ���ִ� Ŭ����
/// </summary>
class SelectGDI
{

private:
	/// ��� ����
	HDC  m_hDC;
	HPEN m_hDefaultPen;
	HBRUSH m_hDefaultBrush;

public:

	/// ������
	SelectGDI(HDC _dc, PEN_TYPE _penType);
	SelectGDI(HDC _dc, BRUSH_TYPE _brushType);
	
	/// �Ҹ���
	~SelectGDI();
};

