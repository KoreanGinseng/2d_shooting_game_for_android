/******************************************************************************/
/*! @file       MissionUI.h
    @brief      ミッションUIクラス定義ファイル
*******************************************************************************/

#ifndef MISSIONUI_H
#define MISSIONUI_H

#include "Mission.h"
#include <DxLib.h>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMissionUI
        @brief  ミッションUIクラス
    *******************************************************************************/
    class CMissionUI
    {
    private:

        /*! ミッション */
        MissionPtr m_Mission;

        /*! 表示用フォントハンドル */
        MyInt m_FontHandle;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      ptr    ミッション
        *******************************************************************************/
        CMissionUI(MissionPtr ptr)
            : m_Mission(ptr)
            , m_FontHandle(-1)
        {
            m_FontHandle = DxLib::LoadFontDataToHandle("fonts/MS_Mincho.dft", 0);
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        ~CMissionUI()
        {
            DxLib::DeleteFontToHandle(m_FontHandle);
        }

        /******************************************************************************/
        /*! 描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
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
