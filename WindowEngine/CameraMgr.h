#pragma once

class CameraMgr
{
	SINGLE(CameraMgr);

private:
	/// 멤버 변수

	Vector2 m_targetLookAt;     // 카메라가 향하는 위치
	Vector2 m_curLookAt;        // 이전 위치와 카메라 보정 위치
	Vector2 m_preLookAt;        // 카메라가 보는 이전 프레임 위치

	Vector2 m_renderGap; // 해상도 중심위치와 카메라 LookAt간의 차이 값

	float m_time;    // 타겟을 따라가는데 걸리는 시간
	float m_speed;   // 타겟을 따라가는 속도
	float m_accTime; // 누적시간

public:
	/// 멤버 함수
	void SetTargetLookAt(Vector2 _look);
	Vector2 GetCurLookAt() { return m_curLookAt; }
	Vector2 GetRenderPos(Vector2 _objPos) { return _objPos - m_renderGap; }
	Vector2 GetRealPos(Vector2 _renderPos) { return _renderPos + m_renderGap; }

	void Init();
	void Update();

private:
	void CalculateRenderGap();

};

