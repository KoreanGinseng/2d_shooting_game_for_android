//
// Created by akasu on 2021/10/13.
//

#ifndef BUTTONUI_H
#define BUTTONUI_H

#include "Button.h"

namespace Shooting2D
{
    class CButtonUI
    {
    private:

        ButtonPtr m_Button;

        MyInt  m_BaseImage;
        MyInt  m_PushImage;
        MyInt  m_OnBaseImage;
        MyInt  m_OnPushImage;

        MyBool m_bPushFlag;

    public:
        explicit CButtonUI(ButtonPtr btn);
        virtual ~CButtonUI();

        MyS32 Load(MyInt baseImg, MyInt pushImg, MyInt onBaseImg, MyInt onPushImg);

        MyS32 Draw();

        MyVoid SetPushFlag(MyBool b);

        MyS32 Release();
    };
}

#endif //BUTTONUI_H
