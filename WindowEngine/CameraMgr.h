#pragma once

class CameraMgr
{
	SINGLE(CameraMgr);

private:
	/// ��� ����

	Vector2 m_targetLookAt;     // ī�޶� ���ϴ� ��ġ
	Vector2 m_curLookAt;        // ���� ��ġ�� ī�޶� ���� ��ġ
	Vector2 m_preLookAt;        // ī�޶� ���� ���� ������ ��ġ

	Vector2 m_renderGap; // �ػ� �߽���ġ�� ī�޶� LookAt���� ���� ��

	float m_time;    // Ÿ���� ���󰡴µ� �ɸ��� �ð�
	float m_speed;   // Ÿ���� ���󰡴� �ӵ�
	float m_accTime; // �����ð�

public:
	/// ��� �Լ�
	void SetTargetLookAt(Vector2 _look);
	Vector2 GetCurLookAt() { return m_curLookAt; }
	Vector2 GetRenderPos(Vector2 _objPos) { return _objPos - m_renderGap; }
	Vector2 GetRealPos(Vector2 _renderPos) { return _renderPos + m_renderGap; }

	void Init();
	void Update();

private:
	void CalculateRenderGap();

};

