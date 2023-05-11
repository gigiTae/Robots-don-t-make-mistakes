#include "pch.h"
#include "CameraMgr.h"



CameraMgr::CameraMgr()
	:m_renderGap{}
	,m_curLookAt{}
	, m_targetLookAt{}
	, m_preLookAt{}
	, m_time(0.f)    // 타겟을 
    , m_speed(0.f)   // 타겟을 따라가는 속도 
    , m_accTime(0.f) // 누적시간
{

}

CameraMgr::~CameraMgr()
{

}

void CameraMgr::SetTargetLookAt(Vector2 _look)
{
}

void CameraMgr::Init()
{
}

void CameraMgr::Update()
{
}

void CameraMgr::CalculateRenderGap()
{
}
