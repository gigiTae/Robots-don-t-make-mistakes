#pragma once
#include "Scene.h"
class Scene_Main :
    public Scene
{
    

public:
    Scene_Main();
    ~Scene_Main();

    //  virtual �Լ��� override Ű���带 ����ؼ� �����Ϸ��� Ȯ�ν�Ű��!
    

    void Exit() override;
    void Enter() override;

};

