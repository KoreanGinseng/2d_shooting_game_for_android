/******************************************************************************/
/*! @file       Bullet.cpp
    @brief      弾クラス実装ファイル
*******************************************************************************/

#include "Bullet.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CBullet::CBullet()
    : CGameObject()
    , m_SpeedX(0.0f)
    , m_SpeedY(0.0f)
    , m_Angle(0.0f)
    , m_Image(-1)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CBullet::~CBullet()
{
}

/******************************************************************************/
/*! 弾の初期化
    @param[in]      px    初期位置Ｘ
    @param[in]      py    初期位置Ｙ
    @param[in]      sx    スピードＸ
    @param[in]      sy    スピードＹ
    @param[in]      iw    画像幅
    @param[in]      ih    画像高さ
    @param[in]      img   画像ＩＤ
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBullet::Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img)
{
    m_bShow  = true;
    m_PosX   = px;
    m_PosY   = py;
    m_SpeedX = sx;
    m_SpeedY = sy;
    m_Angle  = atan2f(sy, sx) + ToRadian(90);
    m_Width  = iw;
    m_Height = ih;
    m_Image  = img;
    m_Radius = 4;
    return k_Success;
}

/******************************************************************************/
/*! 弾の更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBullet::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }
    // 速度で等速移動
    m_PosX += m_SpeedX;
    m_PosY += m_SpeedY;
    // 画面外で消去
    if (m_PosX < -m_Width || m_PosY < -m_Height ||
    m_PosX > k_SceneWidth + m_Width || m_PosY > k_SceneHeight + m_Height)
    {
        m_bShow = false;
    }
    return k_Success;
}

/******************************************************************************/
/*! 弾の描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBullet::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }

    MyInt drawPosX = k_SceneOffsetX + m_PosX + k_BulletDrawOffsetX;
    MyInt drawPosY = k_SceneOffsetY + m_PosY + k_BulletDrawOffsetY;
    DxLib::DrawRotaGraph(drawPosX,  drawPosY, 1.0f, m_Angle, m_Image, true);

#ifdef MY_DEBUG
    DxLib::DrawCircle(m_PosX, m_PosY, m_Radius, DxLib::GetColor(0, 0, 0));
#endif //MY_DEBUG
    return k_Success;
}
