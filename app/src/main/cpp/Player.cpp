/******************************************************************************/
/*! @file       Player.cpp
    @brief      プレイヤー実装ファイル
*******************************************************************************/
#include "Player.h"
#include "TurretArray.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CPlayer::CPlayer()
    : CGameObject()
    , m_Image(0)
    ,m_TurretImage(0)
    , m_Turret()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CPlayer::~CPlayer()
{
}

/******************************************************************************/
/*! プレイヤーの読み込み
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Load()
{
    // 画像を読み込む
    m_Image = DxLib::LoadGraph("image/Plane/Plane1Up.png");
    if (m_Image == -1)
    {
        return -1;
    }
    // 画像の幅と高さを取得
    int w,h;
    DxLib::GetGraphSize(m_Image, &w, &h);
    // 幅と高さを設定
    m_Width  = w;
    m_Height = h;
    // 判定半径設定
    m_Radius = 20;

    // 弾発射用クラスの作成
    m_TurretImage = DxLib::LoadGraph("image/Bullets/06Bullets.png");
    if (m_TurretImage == -1)
    {
        return -1;
    }
    auto turretArray = std::make_shared<CTurretArray>();
    // 3発同時発射
    // 弾の発射オフセット位置定義
    const MyFloat offset[] = {0, 0, 0};
    const MyFloat speedX[] = {2, 0, -2};
    for ( MyS32 cnt = 0; cnt < 3; cnt++)
    {
        auto turret_tmp = turretArray->AddTurret<CTurretSimple>
                (
                 "PlayerBullet",
                 offset[cnt],
                 0.0f, speedX[cnt],
                 -k_PlayerBulletSpeed, k_PlayerBulletWait,
                 m_TurretImage
                 );
    }
    m_Turret = turretArray;
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Initialize()
{
    // 画面下中央から開始
    m_bShow = true;
    m_PosX = static_cast<float>(k_SceneWidth) * 0.5f;
    m_PosY = static_cast<float>(k_SceneHeight - m_Height) - m_Height * 0.05f;
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }

    // 弾の発射
    m_Turret->Update(m_PosX - k_PlayerDrawOffsetX, m_PosY - k_PlayerBulletOffsetY);

    // 移動
    MyS32 touchNum = DxLib::GetTouchInputNum();
    if (touchNum <= 0) { return k_Success; }
    MyInt posX = 0, posY = 0;
    MyS32 result = DxLib::GetTouchInput(touchNum - 1, &posX, &posY, nullptr, nullptr);
    if (result == -1) { return k_Success; }
    m_PosX = posX; m_PosY = posY;

    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }
    MyInt drawPosX = static_cast<MyInt>(k_SceneOffsetX + m_PosX) - m_Width  * 0.5f;
    MyInt drawPosY = static_cast<MyInt>(k_SceneOffsetY + m_PosY) - m_Height * 0.5f;
    DxLib::DrawGraph(drawPosX + k_PlayerDrawOffsetX, drawPosY + k_PlayerDrawOffsetY, m_Image, true);
    DxLib::DrawCircle(m_PosX, m_PosY, m_Radius, DxLib::GetColor(0, 0, 0));
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Release()
{
    DxLib::DeleteGraph(m_Image);
    DxLib::DeleteGraph(m_TurretImage);
    m_Turret.reset();
    return k_Success;
}