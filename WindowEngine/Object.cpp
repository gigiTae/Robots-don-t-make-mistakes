#include "pch.h"
#include "Object.h"

Object::Object()
	:m_alive(true)
	, m_name()
	, m_pos{}
	, m_scale{}
{
}

Object::~Object()
{
}


void Object::Update()
{
}

void Object::Finalupdate()
{
}

void Object::Render(HDC _dc)
{
}


