/******************************************************************************/
/*! @file       GameScene.cpp
    @brief      ゲームシーンクラス実装ファイル
*******************************************************************************/
#include "GameScene.h"
#include "Stage1EnemyPlacement.h"
#include "HitEffectEmitter.h"
#include "ExplosionEffectEmitter.h"
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
        , m_EffectList()
        , m_EmitterArray()
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

    // エフェクトリストの登録
    CSingletonBlackboard<EffectList>::GetInstance().Get<EffectList>()->Add("Effect", m_EffectList);

    // エフェクトエミッターの生成
    MyInt hitEffectImage = DxLib::LoadGraph("image/Effects/pipo-btleffect002.png");
    MyInt explosionEffectImage = DxLib::LoadGraph("image/Effects/pipo-btleffect003.png");
    if (hitEffectImage == -1 || explosionEffectImage == -1) { return k_failure; }
    m_EmitterArray.push_back(CHitEffectEmitter::CreateEmitter(hitEffectImage));
    m_EmitterArray.push_back(CExplosionEffectEmitter::CreateEmitter(explosionEffectImage));

    // エフェクトエミッターの登録
    for (size_t i = 0; i < m_EmitterArray.size(); i++)
    {
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
        .Get<EffectEmitterPtr>()->Add(k_EmitterBoardName[i], m_EmitterArray[i]);
    }
    DxLib::DeleteGraph(hitEffectImage);
    DxLib::DeleteGraph(explosionEffectImage);

    // BGM読み込み
    m_BgmHandle = DxLib::LoadBGM("sounds/bgm/maoudamashii_fantasy_13_loop.ogg");
    if (m_BgmHandle == -1) { return k_failure; }

    // SE読み込み
    m_SEController = std::make_shared<CGameSEController>();
    m_SEController->Load(SEType::Shot     , "sounds/se/maoudamashii_fight_15.ogg");
    m_SEController->Load(SEType::Explosion, "sounds/se/maoudamashii_explosion_06.ogg");
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
    // エフェクトリスト解放
    m_EffectList.clear();
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
    // エフェクト更新
    for (auto& efc : m_EffectList)
    {
        efc->Update();
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
    // 終了したエフェクトの消去
    m_EffectList.erase(
            std::remove_if(
                    m_EffectList.begin(), m_EffectList.end(),
                    [](RKMy(EffectPtr) efc) { return !efc->IsShow(); }),
            m_EffectList.end()
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
    // エフェクト描画
    for (auto& efc : m_EffectList)
    {
        efc->Draw();
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
    // エフェクトリスト解放
    m_EffectList.clear();
    // エフェクトリストの削除
    CSingletonBlackboard<EffectList>::GetInstance().Get<EffectList>()->Delete("Effect");
    // エフェクトエミッターの削除
    for (size_t i = 0; i < m_EmitterArray.size(); i++)
    {
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
        .Get<EffectEmitterPtr>()->Delete(k_EmitterBoardName[i]);
    }
    m_EmitterArray.clear();

    return k_Success;
}