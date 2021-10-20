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
#include "MissionPlayerDead.h"
#include "MissionHideAllEnemy.h"

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
        , m_Score(std::make_shared<CScore>())
        , m_ScoreUI(m_Score)
        , m_Mission(std::make_shared<CMission<CMissionHideAllEnemy, CMissionPlayerDead>>())
        , m_MissionUI(m_Mission)
        , m_BtnBullet{
    std::make_shared<CButton>(k_BtnBullet_1_x1, k_BtnBullet_1_y1, k_BtnBullet_1_x2, k_BtnBullet_1_y2),
    std::make_shared<CButton>(k_BtnBullet_2_x1, k_BtnBullet_2_y1, k_BtnBullet_2_x2, k_BtnBullet_2_y2),
    std::make_shared<CButton>(k_BtnBullet_3_x1, k_BtnBullet_3_y1, k_BtnBullet_3_x2, k_BtnBullet_3_y2)
    }
        , m_BtnUI{CButtonUI(m_BtnBullet[0]), CButtonUI(m_BtnBullet[1]), CButtonUI(m_BtnBullet[2])}
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
    // 敵管理の登録
    CSingletonBlackboard<CEnemyManager>::GetInstance().Get<CEnemyManager>()->Add("EnemyManager", m_EnemyManager);

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

    // スコア登録
    CSingletonBlackboard<ScorePtr>::GetInstance().Get<ScorePtr>()->Add("Score", m_Score);

    // BGM読み込み
    m_BgmHandle = DxLib::LoadBGM("sounds/bgm/maoudamashii_fantasy_13_loop.ogg");
    if (m_BgmHandle == -1) { return k_failure; }

    // SE読み込み
    m_SEController = std::make_shared<CGameSEController>();
    m_SEController->Load(SEType::Shot     , "sounds/se/maoudamashii_fight_15.ogg");
    m_SEController->Load(SEType::Explosion, "sounds/se/maoudamashii_explosion_06.ogg");
    SEService::SetService(m_SEController);

    // ボタン読み込み
    LPKMyS8 files[] =
    {
        "image/Button/Wepon_1.png",
        "image/Button/Wepon_2.png",
        "image/Button/Wepon_3.png",
    };
    for (MyS32 i = 0; i < 3; i++)
    {
        MyInt baseImg = DxLib::LoadGraph(files[i]);
        m_BtnUI[i].Load(
                DxLib::DerivationGraph(1, 0, 25, 17, baseImg),
                DxLib::DerivationGraph(35, 0, 25, 17, baseImg),
                DxLib::DerivationGraph(1, 41, 25, 17, baseImg),
                DxLib::DerivationGraph(35, 41, 25, 17, baseImg)
        );
        DxLib::DeleteGraph(baseImg);
    }
    m_BtnUI[0].SetPushFlag(true);

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

    // スコア初期化
    m_Score->Reset();
    m_ScoreUI.Reset();

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
    // ボタンの更新
    MyBool bBtnPush = false;
    for (MyS32 i = 0; i < 3; i++)
    {
        if (m_BtnBullet[i]->IsPress())
        {
            bBtnPush = true;
            m_BtnUI[i].SetPushFlag(true);
            for (MyS32 j = 0; j < 3; j++)
            {
                if (j == i) continue;
                m_BtnUI[j].SetPushFlag(false);
            }
            m_Player.ChangeTurret(i);
        }
    }
    // 背景の更新
    m_BackGround.Update();
    // プレイヤーの更新
    if (!bBtnPush)
    {
        m_Player.Update();
    }
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

    // ミッション判定
    if (m_Mission->IsFailed())
    {
        SceneChangerService::GetService()->Change("Over", std::make_shared<CSceneChangeEffectFade>(30));
    }
    else if (m_Mission->IsSuccessed())
    {
        SceneChangerService::GetService()->Change("Clear", std::make_shared<CSceneChangeEffectFade>(30));
    }
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
    // ボタン描画
    for (MyS32 i = 0; i < 3; i++)
    {
        m_BtnUI[i].Draw();
    }

    // スコア描画
    m_ScoreUI.Draw();

    // ミッション描画
    m_MissionUI.Draw();

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
    CSingletonBlackboard<BulletList>::GetInstance().
    Get<BulletList>()->Delete("PlayerBullet");
    CSingletonBlackboard<BulletList>::GetInstance().
    Get<BulletList>()->Delete("EnemyBullet");
    // 敵管理開放
    m_EnemyManager.Release();
    CSingletonBlackboard<CEnemyManager>::GetInstance().Get<CEnemyManager>()->Delete("EnemyManager");
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

    // ボタン削除
    for (MyS32 i = 0; i < 3; i++)
    {
        m_BtnUI[i].Release();
    }

    // スコア削除
    CSingletonBlackboard<ScorePtr>::GetInstance().Get<ScorePtr>()->Delete("Score");

    return k_Success;
}