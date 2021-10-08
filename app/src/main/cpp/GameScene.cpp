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
        , m_EnemyBullets()
        , m_BgmHandle(-1)
        , m_SEController()
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
    // プレイヤーの登録
    CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>()->Add("Player", m_Player);
    // 背景の読み込み
    if (m_BackGround.Load() != k_Success) { return k_failure; }
    // 弾リストの登録
    CSingletonBlackboard<BulletList>::GetInstance().
    Get<BulletList>()->Add("PlayerBullet", m_PlayerBullets);
    CSingletonBlackboard<BulletList>::GetInstance().
    Get<BulletList>()->Add("EnemyBullet", m_EnemyBullets);
    // 敵配置生成
    m_EnemyManager.Load(std::make_shared<CStage1EnemyPlacement>());

    // BGM読み込み
    m_BgmHandle = DxLib::LoadBGM("sounds/bgm/maoudamashii_fantasy_13_loop.ogg");
    if (m_BgmHandle == -1)
    {
        return k_failure;
    }

    // SE読み込み
    m_SEController = std::make_shared<CGameSEController>();
    m_SEController->Load(SEType::Shot     , "sounds/se/maoudamashii_fight_15.ogg");
    //m_SEController->Load(SEType::Explosion, "");
    SEService::SetService(m_SEController);

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
    m_EnemyBullets.clear();
    // 敵管理初期化
    m_EnemyManager.Initialize();

    // BGM再生
    DxLib::PlaySoundMem(m_BgmHandle, DX_PLAYTYPE_LOOP);

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
    // 弾更新
    for (auto& blt : m_EnemyBullets)
    {
        blt->Update();
    }
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
    // プレイヤーと敵弾の判定
    for (auto& blt : m_EnemyBullets)
    {
        CCollisionFunction::Collision(m_Player, blt);
    }
    // 終了した弾の消去
    m_PlayerBullets.erase(
            std::remove_if(
                    m_PlayerBullets.begin(), m_PlayerBullets.end(),
                    [](RKMy(BulletPtr) blt) { return !blt->IsShow(); }),
            m_PlayerBullets.end()
            );
    m_EnemyBullets.erase(
            std::remove_if(
                    m_EnemyBullets.begin(), m_EnemyBullets.end(),
                    [](RKMy(BulletPtr) blt) { return !blt->IsShow(); }),
            m_EnemyBullets.end()
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
    // 弾描画
    for (auto& blt : m_EnemyBullets)
    {
        blt->Draw();
    }

    return k_Success;
}

/******************************************************************************/
/*! シーンの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameScene::Release()
{
    // SE解放
    m_SEController.reset();
    SEService::SetService(nullptr);
    // BGM解放
    DxLib::StopSoundMem(m_BgmHandle);
    DxLib::DeleteSoundMem(m_BgmHandle);
    // 背景の解放
    m_BackGround.Release();
    // プレイヤーの解放
    m_Player.Release();
    CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>()->Delete("Player");
    // 弾リスト解放
    m_PlayerBullets.clear();
    m_EnemyBullets.clear();
    // 弾リストの削除
    CSingletonBlackboard<BulletList >::GetInstance().
    Get<BulletList>()->Delete("PlayerBullet");
    CSingletonBlackboard<BulletList >::GetInstance().
    Get<BulletList>()->Delete("EnemyBullet");
    // 敵管理開放
    m_EnemyManager.Release();

    return k_Success;
}