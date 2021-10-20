/******************************************************************************/
/*! @file       GameScene.h
    @brief      ゲームシーンクラス定義ファイル
*******************************************************************************/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "Player.h"
#include "BackGround.h"
#include "EnemyManager.h"
#include "GameSEController.h"
#include "EffectEmitter.h"
#include "ScoreUI.h"
#include "MissionUI.h"
#include "ButtonUI.h"

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

        /*! 背景 */
        CBackGround m_BackGround;

        /*! プレイヤー弾リスト */
        BulletList m_PlayerBullets;

        /*! 敵管理 */
        CEnemyManager m_EnemyManager;

        /*! 敵弾リスト */
        BulletList m_EnemyBullets;

        /*! エフェクトリスト */
        EffectList m_EffectList;

        /*! エミッター */
        EffectEmitterArray m_EmitterArray;

        /*! BGM */
        MyInt m_BgmHandle;

        /*! SE */
        SEControllerPtr<SEType> m_SEController;

        /*! スコア */
        ScorePtr m_Score;

        /*! スコアUI */
        CScoreUI m_ScoreUI;

        /*! ミッション */
        MissionPtr m_Mission;

        /*! ミッションUI */
        CMissionUI m_MissionUI;

        /*! ボタン */
        ButtonPtr m_BtnBullet[3];

        /*! ボタンUI */
        CButtonUI m_BtnUI[3];

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
