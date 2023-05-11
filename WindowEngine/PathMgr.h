#pragma once

/// <summary>
/// ���� : ���� ��� ���� (���ҽ� ������ ��θ� ����η� ��Ÿ��)
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

public: // member func

	// Path Manager �ʱ�ȭ �Լ�
	void init();

	// m_szContentPath�� getter
	const wchar_t* GetContentPath() { return m_szContentPath; }
};