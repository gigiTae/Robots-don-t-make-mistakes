#pragma once
#include "Res.h"

class Texture // Texture�� Res�� �Ļ�Ŭ����
    : public Res
{
private:

    /// ��� ����
    HDC m_dc;
    HBITMAP m_hBit;
    BITMAP  m_bitInfo;

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