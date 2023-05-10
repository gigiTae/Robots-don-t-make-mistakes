#pragma once
#include "Vector2.h"

enum class KEY_STATE
{
	TAP, // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY, // �� �� ����
	NONE, // ������ �ʾҰ�, �������� ������ ���� ����
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LBTN,
	RBTN,

	LAST, //enum�� ��

};

struct tKeyInfo
{
	KEY_STATE eState; // Ű�� ���°�
	bool      bPrevPush;  // ���� �����ӿ��� ���ȴ��� ���� 
};

class KeyMgr
{
	SINGLE(KeyMgr);
public:
	void Init();
	void Update();
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
	Vector2 GetMousePos() { return m_vCurMousePos; }
private:
	vector<tKeyInfo> m_vecKey;
	Vector2 m_vCurMousePos;
};