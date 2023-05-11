#include "pch.h"
#include "ResMgr.h"

// ���ҽ��� �ٷ�� ���� �������
#include "PathMgr.h" // ���� ���
#include "Texture.h" // ��Ʈ�� ����
#include "Res.h"

// ������
ResMgr::ResMgr() {}

// �Ҹ���
ResMgr::~ResMgr()
{
	
}

// ��Ʈ�� �ε�
Texture* ResMgr::LoadTexture(const wstring& _key, const wstring& _relativePath)
{
	// ���ҽ��� �̸� (key)�� �̿��� ��ųʸ����� ���ҽ��� �˻�
	// ���ҽ��� Texture�� �����ͷ� ����
	Texture* pTex = FindTexture(_key);

	if (pTex != nullptr)
		return pTex;

	// ���ҽ������� ���
	wstring resFilePath = PathMgr::GetInst()->GetContentPath();
	resFilePath += _relativePath;

	return nullptr;
}

// ��Ʈ�� ����
Texture* ResMgr::CreateTexture(const wstring& _key, UINT _width, UINT _height)
{
	return nullptr;
}

// ��Ʈ�� �˻�
Texture* ResMgr::FindTexture(const wstring& _key)
{
	return nullptr;
}
