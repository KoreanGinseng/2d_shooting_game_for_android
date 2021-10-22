/******************************************************************************/
/*! @file       ButtonUI.h
    @brief      ボタンUIクラス定義ファイル
*******************************************************************************/

#ifndef BUTTONUI_H
#define BUTTONUI_H

#include "Button.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CButtonUI
        @brief  ボタンUIクラス
    *******************************************************************************/
    class CButtonUI
    {
    private:

        /*! 表示するボタン */
        ButtonPtr m_Button;

        /*! 利用する画像ID */
        MyInt  m_BaseImage;
        MyInt  m_PushImage;
        MyInt  m_OnBaseImage;
        MyInt  m_OnPushImage;

        /*! 押されているフラグ */
        MyBool m_bPushFlag;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      btn    ボタン
        *******************************************************************************/
        explicit CButtonUI(ButtonPtr btn);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CButtonUI();

        /******************************************************************************/
        /*! 読み込み
            @param[in]      baseImg      ベース画像ID
            @param[in]      pushImg      押されている画像ID
            @param[in]      onBaseImg    チェック済みベース画像ID
            @param[in]      onPushImg    チェック済み押されている画像ID
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Load(MyInt baseImg, MyInt pushImg, MyInt onBaseImg, MyInt onPushImg);

        /******************************************************************************/
        /*! 描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Draw();

        /******************************************************************************/
        /*! 押されているフラグの設定
            @param[in]      b    設定する値
        *******************************************************************************/
        MyVoid SetPushFlag(MyBool b)
        {
            m_bPushFlag = b;
        }

        /******************************************************************************/
        /*! 解放
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Release();
    };
}

#endif //BUTTONUI_H
