#include "pch.h"
#include "CameraMgr.h"



CameraMgr::CameraMgr()
	:m_renderGap{}
	,m_curLookAt{}
	, m_targetLookAt{}
	, m_preLookAt{}
	, m_time(0.f)    // Ÿ���� 
    , m_speed(0.f)   // Ÿ���� ���󰡴� �ӵ� 
    , m_accTime(0.f) // �����ð�
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
