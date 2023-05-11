#pragma once

class Res;
class Texture;

/// <summary>
/// 역할 : 리소스 제어 (로드, 생성, 검색)
/// 담당자 : 공준열
/// </summary>
class ResMgr
{
	SINGLE(ResMgr);


private:
	/// 멤버 변수

	map<wstring, Res*> m_mapTex;



	/// FMOD 관련 변수
	FMOD_SYSTEM* m_system;
	FMOD_CHANNEL* m_effectChannel;
	FMOD_CHANNEL* m_effectBGM;


public:
	Texture* LoadTexture(const wstring& _key, const wstring& _relativePath);
	Texture* CreateTexture(const wstring& _key, UINT _width, UINT _height);
	Texture* FindTexture(const wstring& _key);

};

