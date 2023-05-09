#include "pch.h"
#include "TimgMgr.h"

TimgMgr::TimgMgr()
	:m_curentCount{}
	,m_previousCount{}
	,m_frequency{}
	,m_deltaTime{}
	,m_accumulatedDeltaTime{}
	,m_callCount{}
	,m_FramePerSecond{}
{
}

TimgMgr::~TimgMgr()
{
}

void TimgMgr::Init()
{
}

void TimgMgr::Update()
{
}

void TimgMgr::Render()
{
}

double TimgMgr::GetDeltaTime()
{
	return m_deltaTime;
}

UINT TimgMgr::GetFramePerSecond()
{
	return m_FramePerSecond;
}
// 
// #ifdef _DEBUG
// 
// if (m_deltaTime > 0.1)
// {
// 	m_deltaTime = 0.1;
// }
// #endif