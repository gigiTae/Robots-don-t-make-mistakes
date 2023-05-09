#pragma once



class Res
{

private:
	/// 멤버변수
	wstring m_key;          // 리소스 키
	wstring m_relativePath; // 리소스 상대경로

public:
	/// 멤버 함수
	void SetKey(const wstring& _key) { m_key = _key; }
	void SetRelativePath(const wstring& _path) { m_relativePath = _path; }

	const wstring& GetKey() { return m_key; }
	const wstring& GetRelativePath() { return m_relativePath; }

public:
	
	/// 생성자
	Res();

	/// 소멸자
	virtual ~Res();
};

