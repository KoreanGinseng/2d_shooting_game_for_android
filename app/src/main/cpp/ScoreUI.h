/******************************************************************************/
/*! @file       ScoreUI.h
    @brief      スコアクラス定義ファイル
*******************************************************************************/

#ifndef SCOREUI_H
#define SCOREUI_H

#include "Score.h"
#include <DxLib.h>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CScoreUI
        @brief  スコアUIクラス
    *******************************************************************************/
    class CScoreUI
    {
    private:

        /*! スコア */
        ScorePtr m_Score;
        MyS32 m_CurrentScore;

        /*! 表示用フォントハンドル */
        MyInt m_FontHandle;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      ptr          スコア
        *******************************************************************************/
        explicit CScoreUI(ScorePtr ptr)
            : m_Score(ptr)
            , m_CurrentScore(0)
            , m_FontHandle(-1)
        {
            m_FontHandle = DxLib::LoadFontDataToHandle("fonts/MS_Mincho.dft", 0);
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        ~CScoreUI()
        {
            DxLib::DeleteFontToHandle(m_FontHandle);
        }

        /******************************************************************************/
        /*! リセット
        *******************************************************************************/
        MyVoid Reset() noexcept
        {
            m_CurrentScore = 0;
        }

        /******************************************************************************/
        /*! シーンの描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
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
