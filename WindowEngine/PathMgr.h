#pragma once

/// <summary>
/// 역할 : 파일 경로 제어
/// 담당자 : 공준열
/// </summary>
class PathMgr
{
	// Singleton 매크로 (define.h에 정의)
	// #define SINGLE(type) public:static type* GetInst() {static type mgr; return &mgr;} private:type(); ~type();
	/*
	public:
		static PathMgr* GetInst() { static PathMgr pathMgr; return &pathMgr; }
	private:
		PathMgr();
		~PathMgr();
	*/
	SINGLE(PathMgr);

private: // member variable

	// sz : NULL로 끝나는 문자열 (헝가리안 표기법)
	// wchar_t : 2바이트의 크기, 유니코드 표현가능 (경로에 한글이 포함되어 있을 수 있기 때문..?)
	wchar_t m_szContentPath[256];

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ //
	// 이 변수의 용도?
	// 어디에서도 참조되지 않는다?
	wchar_t m_szRelativePath[256];

public: // member func

	// Path Manager 초기화 함수
	void init();

	// m_szContentPath의 getter
	const wchar_t* GetContentPath();

	// string - char (1byte) / wstring - wchar_t (2byte)
	wstring GetRelativePath(const wchar_t* _filepath);
};