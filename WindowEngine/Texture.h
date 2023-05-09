#pragma once
#include "Res.h"

class Texture // Texture는 Res의 파생클래스
    : public Res
{
private:

    /// 멤버 변수
    HDC m_dc;
    HBITMAP m_hBit;
    BITMAP  m_bitInfo;

public:

    /// 멤버 함수
    void Load(const wstring& _filePath);
    void Create(UINT _width, UINT _height);
    UINT GetWidth() { return m_bitInfo.bmWidth; }
    UINT GetHeight() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }

private:

    Texture();
    virtual ~Texture();

    /// friend class 선언을 통해서 ResMgr는 Texture의 private에 접근이 가능하다
    /// 즉 Texture는 ResMgr를 통해서만 생성하겠다라는 의미이다. 
    friend class ResMgr;
};