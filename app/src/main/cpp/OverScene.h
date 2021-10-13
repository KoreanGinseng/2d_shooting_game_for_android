//
// Created by akasu on 2021/10/13.
//

#ifndef OVERSCENE_H
#define OVERSCENE_H

#include "Scene.h"

namespace Shooting2D
{
    class COverScene : public IScene
    {
    private:
        MyBool m_bPressReturn;

        MyBool m_bSceneChange;

        MyInt m_Image;

        MyInt m_FontHandle;

    public:

        COverScene();

        virtual ~COverScene();

        virtual MyS32 Load() override;

        virtual MyS32 Initialize() override;

        virtual MyS32 Update() override;

        virtual MyS32 Draw() override;

        virtual MyS32 Release() override;
    };
}


#endif //OVERSCENE_H
