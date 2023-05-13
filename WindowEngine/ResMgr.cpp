#include "pch.h"
#include "ResMgr.h"

// ���ҽ��� �ٷ�� ���� �������
#include "PathMgr.h" // ���� ���
#include "Texture.h" // ��Ʈ�� ����
#include "Res.h"

// ������
ResMgr::ResMgr()
{}

// �Ҹ���
ResMgr::~ResMgr()
{
	// ���ҽ� ���� map�� �� �޸� ����

}

// ��Ʈ�� �ε�
// ���ҽ� �̸��� ��θ� �̿��� map���� ��Ʈ�� ���ҽ��� �ε�
// Texture*�� ��ȯ
Texture* ResMgr::LoadTexture(const wstring& _key, const wstring& _relativePath)
{
	// ���ҽ��� �̸� (key)�� �̿��� ��ųʸ����� ���ҽ��� �˻�
	// ���ҽ��� Texture*�� ����
	Texture* pTex = FindTexture(_key);

	if (pTex != nullptr)
		return pTex;
	else
	{
		// ���ҽ������� ��θ� ���� ����
		wstring resFilePath = PathMgr::GetInst()->GetContentPath();
		resFilePath += _relativePath;

		pTex = new Texture;
		pTex->Load(resFilePath); // �ش� ����� ���ҽ��� �� Load

		// map�� ����
		pTex->SetKey(_key);
		pTex->SetRelativePath(_relativePath);

		m_mapTex.insert(make_pair(_key, pTex));

		return pTex;
	}
}

// ��Ʈ�� ����
Texture* ResMgr::CreateTexture(const wstring& _key, UINT _width, UINT _height)
{
	// key�� �̿��� ���ҽ� Ž��
	Texture* pTex = FindTexture(_key);

	// pTex�� ���� ��������� �� ���ҽ��� return
	if (nullptr != pTex)
		return pTex;
	// pTex�� �ƹ��͵� ������ ���� ��Ʈ�� ����
	else
	{
		pTex = new Texture;
		pTex->Create(_width, _height);
		pTex->SetKey(_key);

		m_mapTex.insert(make_pair(_key, pTex));
		return pTex;
	}
}

// ��Ʈ�� �˻�
Texture* ResMgr::FindTexture(const wstring& _key)
{
	// �ݺ���
	std::map<wstring, Res*>::iterator iter = m_mapTex.find(_key);
	
	// iter �ݺ��ڸ� �̿��� map�� ������ key�� Ž��
	// iter->second : map�� 2��° ���� value�� ��ȯ�ϴµ�
	// (Texture*)�� ��������� ĳ���� ���־�, "�ٿ�ĳ����"
	// iter->second�� ��ȯ���� Res*�̰� Res�� �Ļ�Ŭ������ Texture*�� �ٿ�ĳ���� ����
	if (iter != m_mapTex.end())
		return (Texture*)iter->second;
	else
		return nullptr; // ã�Ҵµ� ������ nullptr ��ȯ
}
