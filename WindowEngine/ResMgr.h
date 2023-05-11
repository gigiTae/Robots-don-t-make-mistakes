#pragma once

// Res와 Texture 클래스를 전방 선언
class Res;
class Texture;

/// <summary>
/// 역할 : 리소스 제어를 총괄 (로드, 생성, 검색)
/// 담당자 : 공준열
/// </summary>
class ResMgr
{
	SINGLE(ResMgr);


private:

	/// 멤버 변수
	// 리소스를 key - value 형태로 저장
	map<wstring, Res*> m_mapTex;

public:
	Texture* LoadTexture(const wstring& _key, const wstring& _relativePath);
	Texture* CreateTexture(const wstring& _key, UINT _width, UINT _height);
	Texture* FindTexture(const wstring& _key);

};