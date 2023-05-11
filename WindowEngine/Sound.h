#pragma once
#include "Res.h"

class Sound :
    public Res
{

private:
    FMOD_SOUND* m_sound;


private:

    /// Sound는 리소스 매니져를 통해서 호출
    Sound();
    virtual ~Sound();
    friend class ResMgr;
};

