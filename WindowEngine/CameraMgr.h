#pragma once

class CameraMgr
{
	SINGLE(CameraMgr);

private:
	/// ��� ����

	Vector2 m_targetLookAt;     // ī�޶� ���ϴ� ��ġ
	Vector2 m_curLookAt;  // ���� ��ġ�� ������ġ ���� ��ġ
	Vector2 m_preLookAt;  // ī�޶� ���� ���� ������ ��ġ

	Vector2 m_rederGap; // �ػ� �߽���ġ�� ī�޶� LookAt���� ���� ��

	float m_time; // Ÿ���� ���󰡴µ� �ɸ��� �ð�
	float m_speed; // Ÿ���� ���󰡴� �ӵ�
	float m_accTime; // �����ð�

public:
	/// ��� �Լ�


public:
	void Init();
	void Update();


};

