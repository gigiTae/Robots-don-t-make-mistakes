#pragma once

// Res�� Texture Ŭ������ ���� ����
class Res;
class Texture;

/// <summary>
/// ���� : ���ҽ� ��� �Ѱ� (�ε�, ����, �˻�)
/// ����� : ���ؿ�
/// </summary>
class ResMgr
{
	SINGLE(ResMgr);


private:

	/// ��� ����
	// ���ҽ��� key - value ���·� ����
	map<wstring, Res*> m_mapTex;

public:
	Texture* LoadTexture(const wstring& _key, const wstring& _relativePath);
	Texture* CreateTexture(const wstring& _key, UINT _width, UINT _height);
	Texture* FindTexture(const wstring& _key);

};