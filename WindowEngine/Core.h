#pragma once

class Core
{
	SINGLE(Core);

private:
	HWND  m_hWnd;       // ���� ������ �ڵ�
	POINT m_Resolution; // ���� ������ �ػ�
	HDC   m_hDC;        // ���� ������ Draw DC



public:

	// ���� ���۽ÿ� ȣ���ϴ� �Լ�
	int Init(HWND _hWnd, POINT _resolution);  
	
	// ���� ����
	void Progress();



};

