//
// Created by akasu on 2021/10/13.
//

#ifndef MISSIONUI_H
#define MISSIONUI_H

#include "Mission.h"
#include <DxLib.h>

namespace Shooting2D
{
    class CMissionUI
    {
    private:
        MissionPtr m_Mission;

        MyInt m_FontHandle;

    public:
        CMissionUI(MissionPtr ptr)
            : m_Mission(ptr)
            , m_FontHandle(-1)
        {
            m_FontHandle = DxLib::LoadFontDataToHandle("fonts/MS_Mincho.dft", 0);
        }

        ~CMissionUI()
        {
            DxLib::DeleteFontToHandle(m_FontHandle);
        }

        MyS32 Draw()
        {
            MyU32 colorWhite = DxLib::GetColor(255, 255, 255);
            MyU32 colorGray  = DxLib::GetColor(128, 128, 128);
            MyU32 colorBlack = DxLib::GetColor(  0,   0,   0);
            if (m_Mission->IsFailed())
            {
                DxLib::DrawStringToHandle(0, 0, "GameOver", colorWhite, m_FontHandle);
            }
            else if (m_Mission->IsSuccessed())
            {
                DxLib::DrawStringToHandle(0, 0, "GameClear", colorWhite, m_FontHandle);
            }
            return k_Success;
        }
    };
}

#endif //MISSIONUI_H
