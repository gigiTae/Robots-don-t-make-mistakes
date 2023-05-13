#pragma once
#include "Res.h"

/// <summary>
/// ���� : ��Ʈ���� �ε� �� ����
/// ����� : ���ؿ�
/// </summary>
class Texture
    : public Res
{
private:

    /// ��� ����
    // Bitmap�� �׸��� ���� ������
    HDC m_dc; // ��ȭ��
    HBITMAP m_hBit; // ��Ʈ�� �ڵ�
    BITMAP  m_bitInfo; // ��Ʈ�� ����

public:

    /// ��� �Լ�
    void Load(const wstring& _filePath);
    void Create(UINT _width, UINT _height);
    UINT GetWidth() { return m_bitInfo.bmWidth; }
    UINT GetHeight() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }

private:

    Texture();
    virtual ~Texture();

    /// friend class ������ ���ؼ� ResMgr�� Texture�� private�� ������ �����ϴ�
    /// �� Texture�� ResMgr�� ���ؼ��� �����ϰڴٶ�� �ǹ��̴�. 
    friend class ResMgr;
};