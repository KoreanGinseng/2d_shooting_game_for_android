/******************************************************************************/
/*! @file       Enemy.cpp
    @brief      敵クラス実装ファイル
*******************************************************************************/

#include "Enemy.h"
#include <DxLib.h>
#include "EffectEmitter.h"
#include "Score.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CEnemy::CEnemy()
    : CGameObject()
    , m_Angle(0.0f)
    , m_Image(-1)
    , m_HP(0)
    , m_Turret()
    , m_Move()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CEnemy::~CEnemy()
{
}

/******************************************************************************/
/*! 初期化
    @param[in]      px     初期座標X
    @param[in]      py     初期座標Y
    @param[in]      img    画像ID
    @param[in]      tcp    砲台生成機
    @param[in]      mcp    移動生成機
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemy::Initialize(MyFloat px, MyFloat py, MyInt img, TurretCreatorPtr tcp, MoveCreatorPtr mcp)
{
    // 移動を登録
    m_Move   = mcp->Create();
    m_bShow  = true;
    m_HP     = 3;
    m_PosX   = px;
    m_PosY   = py;
    m_Angle  = atan2f(m_Move->GetSpeedY(), m_Move->GetSpeedX()) - ToRadian(90);
    MyInt iw, ih;
    DxLib::GetGraphSize(img, &iw, &ih);
    m_Width  = iw; m_Height = ih;
    m_Radius = 10;
    m_Image  = img;

    // 砲台を登録
    m_Turret = tcp->Create();
    return k_Success;
}

/******************************************************************************/
/*! 更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemy::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }
    // 移動
    if (m_Move) { m_Move->Update(m_PosX, m_PosY); }
    // 画面外で消去
    if (m_PosX < -m_Width || m_PosY < -m_Height ||
        m_PosX > k_SceneWidth + m_Width ||
        m_PosY > k_SceneHeight + m_Height)
    {
        m_bShow = false;
    }
    // 弾発射
    m_Turret->Update(m_PosX, m_PosY);
    return k_Success;
}

/******************************************************************************/
/*! 描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemy::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }
    DxLib::DrawRotaGraph(k_SceneOffsetX + m_PosX, k_SceneOffsetY + m_PosY, 1.0f, m_Angle, m_Image, true);

#ifdef MY_DEBUG
    DxLib::DrawCircle(m_PosX, m_PosY, m_Radius, DxLib::GetColor(0, 0, 0));
#endif //MY_DEBUG
    return k_Success;
}

/******************************************************************************/
/*! ダメージ処理
    @param[in]      dmg    ダメージ
*******************************************************************************/
MyVoid CEnemy::Damage(MyS32 dmg)
{
    m_HP -= dmg;
    // HPがなくなれば非表示にする
    if (m_HP <= 0)
    {
        m_bShow = false;
        // エフェクト発生
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
                .Get<EffectEmitterPtr>("Explosion")->Emit(m_PosX, m_PosY);
        // スコア加算
        CSingletonBlackboard<ScorePtr>::GetInstance().Get<ScorePtr>("Score")->Add(100);
    }
}