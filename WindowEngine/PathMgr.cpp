#include "pch.h" // include useful header & using namespace
#include "PathMgr.h"

// no_argument constructor
// ������ �ʱ�ȭ ����Ʈ ��� (�� ������ ȿ�������� �ʱ�ȭ) or const ������� �ʱ�ȭ
PathMgr::PathMgr() : m_szContentPath{}
{}

// de - constructor
PathMgr::~PathMgr()
{}

void PathMgr::init()
{
	// ���� �۾� ���丮�� ��θ� �������� �Լ� (Windows.h�� �Լ�)
	// first : ����� �ִ� ����
	// second : ����� ���ڿ� ���� ����
	// m_szContentPath : L"C:\\Users\\USER-PC\\Documents\\GitHub\\WindowEngine\\WindowEngine"
	GetCurrentDirectory(255, m_szContentPath);

	// ���� �۾� ���丮�� ����� ���� ���ϱ�
	// wcslen : strlen()�� wide ����
	int length = (int)wcslen(m_szContentPath);

	// ���� ������
	// ���� �۾� ���丮�� ��ΰ� ����Ǿ� �ִ� ���ڿ��� ������ index���� ù��° index���� ��ȸ
	for (int i = length - 1; i >= 0; i--)
	{
		// L"~\\WindowEngine\\WindowEngine"�� ������ ���� ����
		// L"~\\WindowEngine"
		if (m_szContentPath[i] == '\\') // '\' �� ���ڸ� ã����
		{
			m_szContentPath[i] = '\0'; // NULL ���� (���ڿ��� ��)
			break;
		}
	}

	// L"~\\WindowEngine"�� ������ ���� ����
	// L"~\\WindowEngine\\Resource"
	// wcscat_s : ���ڿ� ���ۿ� ���ڿ� �̾���̱�
	wcscat_s(m_szContentPath, 255, L"\\Resource");
}