#pragma once

// deltaTime / FPS 관리 클래스
class TimgMgr
{
	SINGLE(TimgMgr);

public:
	void Init();
	void Update();
	void Render();
	 
	UINT GetFps() { return m_fps; }
	double GetDeltaTime() { return m_deltaTime; }

private:
	LARGE_INTEGER m_curentCount;
	LARGE_INTEGER m_previousCount;
	LARGE_INTEGER m_frequency;
	
	double m_deltaTime;
	double m_accumulatedDeltaTime;

	UINT m_callCount;
	UINT m_fps;

};

