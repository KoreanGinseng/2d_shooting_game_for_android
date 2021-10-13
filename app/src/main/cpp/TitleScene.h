//
// Created by akasu on 2021/10/12.
//

#ifndef TEST_TITLESCENE_H
#define TEST_TITLESCENE_H

#include "Scene.h"

namespace Shooting2D
{
    class CTitleScene : public IScene
    {
    private:
        MyBool m_bPressReturn;
        MyBool m_bSceneChange;
        MyInt  m_Image;
        MyInt  m_FontHandle;

    public:
        CTitleScene();
        virtual ~CTitleScene();
        virtual MyS32 Load() override;
        virtual MyS32 Initialize() override;
        virtual MyS32 Update() override;
        virtual MyS32 Draw() override;
        virtual MyS32 Release() override;
    };

}


#endif //TEST_TITLESCENE_H