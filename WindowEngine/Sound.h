#pragma once
#include "Res.h"

class Sound :
    public Res
{

private:
    FMOD_SOUND* m_sound;


private:

    /// Sound�� ���ҽ� �Ŵ����� ���ؼ� ȣ��
    Sound();
    virtual ~Sound();
    friend class ResMgr;
};

