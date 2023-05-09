#pragma once


class TimgMgr
{
	SINGLE(TimgMgr);

private:
	LARGE_INTEGER m_curentCount;
	LARGE_INTEGER m_previousCount;
	LARGE_INTEGER m_frequency;
	
	double m_deltaTime;
	double m_accumulatedDeltaTime;

	UINT m_callCount;
	UINT m_FramePerSecond;

public:
	void Init();
	void Update();
	void Render();

	double GetDeltaTime();
	UINT GetFramePerSecond();
};

