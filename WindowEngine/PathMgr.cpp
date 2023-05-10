#include "pch.h" // include useful header & using namespace
#include "PathMgr.h"

// no_argument constructor
// 생성자 초기화 리스트 사용 (더 빠르고 효율적으로 초기화)
PathMgr::PathMgr() : m_szContentPath{}, m_szRelativePath{}
{}

// de - constructor
PathMgr::~PathMgr()
{}

void PathMgr::init()
{
	// 현재 작업 디렉토리의 경로를 가져오는 함수 (Windows.h의 함수)
	// first : 경로의 최대 길이
	// second : 저장될 문자열 버퍼 공간
	// m_szContentPath : L"C:\\Users\\USER-PC\\Documents\\GitHub\\WindowEngine\\WindowEngine"
	GetCurrentDirectory(255, m_szContentPath);

	// 현재 작업 디렉토리의 경로의 길이 구하기
	// wcslen : strlen()의 wide 버전
	int length = (int)wcslen(m_szContentPath);

	// 상위 폴더로
	// 현재 작업 디렉토리의 경로가 저장되어 있는 문자열의 마지막 index부터 첫번째 index까지 순회
	for (int i = length - 1; i >= 0; i--)
	{
		// L"~\\WindowEngine\\WindowEngine"을 다음과 같이 변경
		// L"~\\WindowEngine"
		if (m_szContentPath[i] == '\\') // '\' 이 문자를 찾으면
		{
			m_szContentPath[i] = '\0'; // NULL 삽입 (문자열의 끝)
			break;
		}
	}

	// L"~\\WindowEngine"을 다음과 같이 변경
	// L"~\\WindowEngine\\Resource"
	// wcscat_s : 문자열 버퍼에 문자열 이어붙이기
	wcscat_s(m_szContentPath, 255, L"\\Resource");
}

const wchar_t* PathMgr::GetContentPath()
{
	return m_szContentPath;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ //
// 이 함수의 용도?
// 어디에서도 참조되지 않는다?
wstring PathMgr::GetRelativePath(const wchar_t* _filepath)
{
	wstring strFilePath = _filepath;

	size_t iAbsLen = wcslen(m_szContentPath);
	size_t iFullLen = strFilePath.length();

	wstring strRelativePath = strFilePath.substr(iAbsLen, iFullLen - iAbsLen);

	return strRelativePath;
}