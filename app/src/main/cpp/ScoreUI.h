//
// Created by akasu on 2021/10/09.
//

#ifndef SCOREUI_H
#define SCOREUI_H

#include "Score.h"
#include <DxLib.h>

namespace Shooting2D
{
    class CScoreUI
    {
    private:
        ScorePtr m_Score;
        MyS32 m_CurrentScore;
        MyInt m_FontHandle;

    public:
        explicit CScoreUI(ScorePtr ptr)
            : m_Score(ptr)
            , m_CurrentScore(0)
            , m_FontHandle(-1)
        {
            m_FontHandle = DxLib::LoadFontDataToHandle("fonts/MS_Mincho.dft", 0);
        }

        ~CScoreUI()
        {
            DxLib::DeleteFontToHandle(m_FontHandle);
        }

        MyVoid Reset() noexcept
        {
            m_CurrentScore = 0;
        }

        MyS32 Draw()
        {
            // 表示スコアを徐々に変化させる
            if (m_CurrentScore != m_Score->Get())
            {
                MyS32 diff = m_Score->Get() - m_CurrentScore;
                if (diff / 10 != 0)
                {
                    diff /= 10;
                }
                m_CurrentScore += diff;
            }
            DxLib::DrawFormatStringToHandle(12, 12, DxLib::GetColor(255, 255, 255), m_FontHandle, "Score : %010d", m_CurrentScore);
            return k_Success;
        }
    };
}

#endif //SCOREUI_H
