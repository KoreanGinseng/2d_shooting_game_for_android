/******************************************************************************/
/*! @file       GameScene.h
    @brief      ゲームシーンクラス定義ファイル
*******************************************************************************/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "IScene.h"
#include "Player.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CGameScene
        @brief  ゲームシーンクラス
    *******************************************************************************/
    class CGameScene : public IScene
    {
    private:

        /*! プレイヤー */
        CPlayer m_Player;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        explicit CGameScene();

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CGameScene() final;

        /******************************************************************************/
        /*! シーンの読み込み
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Load() final;

        /******************************************************************************/
        /*! シーンの初期化
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Initialize() final;

        /******************************************************************************/
        /*! シーンの更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update() final;

        /******************************************************************************/
        /*! シーンの描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Draw() final;

        /******************************************************************************/
        /*! シーンの解放
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Release() final;
    };

}


#endif //GAMESCENE_H
