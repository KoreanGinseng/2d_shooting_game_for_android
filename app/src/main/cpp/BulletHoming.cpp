/******************************************************************************/
/*! @file       BulletHoming.cpp
    @brief      追跡弾クラス実装ファイル
*******************************************************************************/

#include "BulletHoming.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      target    追跡対象
*******************************************************************************/
CBulletHoming::CBulletHoming(GameObjectPtr target)
    : CBullet()
    , m_Target(target)
    , m_MaxSpeed(0.0f)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CBulletHoming::~CBulletHoming()
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
MyS32 CBulletHoming::Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img)
{
    MyS32 result = CBullet::Initialize(px, py, sx, sy, iw, ih, img);
    m_MaxSpeed = sqrtf(sx * sx + sy * sy);
    return result;
}

/******************************************************************************/
/*! 弾の更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBulletHoming::Update()
{
    // ターゲットがいる場合
    if (m_Target && m_Target->IsShow())
    {
        // 追跡する
        MyFloat dx = m_Target->GetPosX() - m_PosX;
        MyFloat dy = m_Target->GetPosY() - m_PosY;
        MyFloat d  = sqrtf(dx * dx + dy * dy);
        MyFloat nx = dx / d;
        MyFloat ny = dy / d;
        m_SpeedX  += nx * m_MaxSpeed * 0.05f;
        m_SpeedY  += ny * m_MaxSpeed * 0.05f;
        MyFloat spdd = sqrtf(m_SpeedX * m_SpeedX + m_SpeedY * m_SpeedY);
        if (spdd >= m_MaxSpeed)
        {
            m_SpeedX /= spdd;
            m_SpeedY /= spdd;
            m_SpeedX *= m_MaxSpeed;
            m_SpeedY *= m_MaxSpeed;
        }
        m_Angle = atan2f(m_SpeedY, m_SpeedX) + ToRadian(90);
    }
    // ターゲットが死んだ場合最大速度まで加速
    else
    {
        MyFloat spdd = sqrtf(m_SpeedX * m_SpeedX + m_SpeedY * m_SpeedY);
        m_SpeedX /= spdd;
        m_SpeedY /= spdd;
        spdd += m_MaxSpeed * 0.05f;
        if (spdd >= m_MaxSpeed)
        {
            spdd = m_MaxSpeed;
        }
        m_SpeedX *= spdd;
        m_SpeedY *= spdd;
        m_Angle   = atan2f(m_SpeedY, m_SpeedX) + ToRadian(90);
    }
    return CBullet::Update();
}
