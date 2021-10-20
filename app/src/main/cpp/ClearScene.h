//
// Created by akasu on 2021/10/13.
//

#ifndef CLEARSCENE_H
#define CLEARSCENE_H

#include "Scene.h"
#include "ButtonUI.h"

namespace Shooting2D
{
    class CClearScene : public IScene
    {
    private:
        MyBool m_bSceneChange;
        MyInt m_Image;
        MyInt m_LogoImage;
        ButtonPtr m_BtnTitle;
        CButtonUI m_BtnUI;
    public:

        CClearScene();

        virtual ~CClearScene();

        virtual MyS32 Load() override;

        virtual MyS32 Initialize() override;

        virtual MyS32 Update() override;

        virtual MyS32 Draw() override;

        virtual MyS32 Release() override;
    };

}


#endif //CLEARSCENE_H
