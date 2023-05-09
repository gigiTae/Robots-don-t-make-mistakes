#pragma once

/// <summary>
/// ���� : ���� ��� ����
/// ����� : ���ؿ�
/// </summary>
class PathMgr
{
	// Singleton ��ũ�� (define.h�� ����)
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

	// sz : NULL�� ������ ���ڿ� (�밡���� ǥ���)
	// wchar_t : 2����Ʈ�� ũ��, �����ڵ� ǥ������ (��ο� �ѱ��� ���ԵǾ� ���� �� �ֱ� ����..?)
	wchar_t m_szContentPath[256];

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ //
	// �� ������ �뵵?
	// ��𿡼��� �������� �ʴ´�?
	wchar_t m_szRelativePath[256];

public: // member func

	// Path Manager �ʱ�ȭ �Լ�
	void init();

	// m_szContentPath�� getter
	const wchar_t* GetContentPath();

	// string - char (1byte) / wstring - wchar_t (2byte)
	wstring GetRelativePath(const wchar_t* _filepath);
};