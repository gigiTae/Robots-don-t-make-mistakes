#include "pch.h"
#include "ResMgr.h"

// 리소스를 다루기 위한 헤더파일
#include "PathMgr.h" // 파일 경로
#include "Texture.h" // 비트맵 정보
#include "Res.h"

// 생성자
ResMgr::ResMgr() {}

// 소멸자
ResMgr::~ResMgr()
{
	
}

// 비트맵 로드
Texture* ResMgr::LoadTexture(const wstring& _key, const wstring& _relativePath)
{
	// 리소스의 이름 (key)을 이용해 딕셔너리에서 리소스를 검색
	// 리소스를 Texture의 포인터로 저장
	Texture* pTex = FindTexture(_key);

	if (pTex != nullptr)
		return pTex;

	// 리소스파일의 경로
	wstring resFilePath = PathMgr::GetInst()->GetContentPath();
	resFilePath += _relativePath;

	return nullptr;
}

// 비트맵 생성
Texture* ResMgr::CreateTexture(const wstring& _key, UINT _width, UINT _height)
{
	return nullptr;
}

// 비트맵 검색
Texture* ResMgr::FindTexture(const wstring& _key)
{
	return nullptr;
}
