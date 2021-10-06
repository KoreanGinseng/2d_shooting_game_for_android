/******************************************************************************/
/*! @file       GameScene.cpp
    @brief      ゲームシーンクラス実装ファイル
*******************************************************************************/
#include "GameScene.h"
#include "Stage1EnemyPlacement.h"
#include "CollisionFunction.h"
#include "CollisionPlayerEnemy.h"
#include "CollisionPlayerBullet.h"
#include "CollisionEnemyBullet.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CGameScene::CGameScene()
        : IScene()
        , m_Player()
        , m_BackGround()
        , m_PlayerBullets()
        , m_EnemyManager()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CGameScene::~CGameScene()
{
}

/******************************************************************************/
/*! シーンの読み込み
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Load()
{
    // プレイヤーの読み込み
    if (m_Player.Load() != k_Success) { return k_failure; }
    // 背景の読み込み
    if (m_BackGround.Load() != k_Success) { return k_failure; }
    // 弾リストの登録
    CSingletonBlackboard<BulletList>::GetInstance().
    Get<BulletList>()->Add("PlayerBullet", m_PlayerBullets);
    // 敵配置生成
    m_EnemyManager.Load(std::make_shared<CStage1EnemyPlacement>());
    return k_Success;
}

/******************************************************************************/
/*! シーンの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Initialize()
{
    // プレイヤーの初期化
    m_Player.Initialize();
    // 背景の初期化
    m_BackGround.Initialize();
    // 弾リスト解放
    m_PlayerBullets.clear();
    // 敵管理初期化
    m_EnemyManager.Initialize();

    return k_Success;
}

/******************************************************************************/
/*! シーンの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Update()
{
    // 背景の更新
    m_BackGround.Update();
    // プレイヤーの更新
    m_Player.Update();
    // 弾更新
    for (auto& blt : m_PlayerBullets)
    {
        blt->Update();
    }
    // 敵更新
    m_EnemyManager.Update(m_BackGround.GetScroll());
    // 接触判定
    for (auto& enemy : m_EnemyManager.GetEnemyList())
    {
        // プレイヤーと敵の判定
        CCollisionFunction::Collision(m_Player, enemy);
        // 敵と弾の判定
        for (auto& bullet : m_PlayerBullets)
        {
            CCollisionFunction::Collision(enemy, bullet);
        }
    }
    // 終了した弾の消去
    m_PlayerBullets.erase(
            std::remove_if(
                    m_PlayerBullets.begin(), m_PlayerBullets.end(),
                    [](RKMy(BulletPtr) blt) { return !blt->IsShow(); }),
            m_PlayerBullets.end()
            );

    return k_Success;
}

/******************************************************************************/
/*! シーンの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Draw()
{
    // 背景の描画
    m_BackGround.Draw();
    // プレイヤーの描画
    m_Player.Draw();
    // 弾描画
    for (auto& blt : m_PlayerBullets)
    {
        blt->Draw();
    }
    // 敵描画
    m_EnemyManager.Draw();

    return k_Success;
}

/******************************************************************************/
/*! シーンの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Release()
{
    // 背景の解放
    m_BackGround.Release();
    // プレイヤーの解放
    m_Player.Release();
    // 弾リスト解放
    m_PlayerBullets.clear();
    // 弾リストの削除
    CSingletonBlackboard<BulletList >::GetInstance().
    Get<BulletList>()->Delete("PlayerBullet");
    // 敵管理開放
    m_EnemyManager.Release();

    return k_Success;
}