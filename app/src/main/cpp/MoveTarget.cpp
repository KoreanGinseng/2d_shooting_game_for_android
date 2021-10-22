/******************************************************************************/
/*! @file       MoveTarget.cpp
    @brief      標的へ向かって移動するクラス定義ファイル
*******************************************************************************/

#include "MoveTarget.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]  speed     移動速度
    @param[in]  tx        対象座標X
    @param[in]  ty        対象座標Y
*******************************************************************************/
CMoveTarget::CMoveTarget(MyFloat speed, MyFloat tx, MyFloat ty)
    : CMoveSimple(0, 0)
    , m_TargetX(tx)
    , m_TargetY(ty)
    , m_Speed(speed)
    , m_bSetSpeed(false)
{
}

/******************************************************************************/
/*! 更新
    @param[in,out]  px    移動させる座標X
    @param[in,out]  py    移動させる座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CMoveTarget::Update(MyFloat &px, MyFloat &py)
{
    MyFloat dx = m_TargetX - px;
    MyFloat dy = m_TargetY - py;
    MyFloat d = sqrtf(dx * dx + dy * dy);
    MyLOGD("d : %f\n", d);
    // 差分チェックして近ければ強制移動で終了
    if (d < 10.0f)
    {
        px = m_TargetX;
        py = m_TargetY;
        m_SpeedX = m_SpeedY = 0;
        m_bSetSpeed = false;
        return k_Success;
    }
    // 速度を設定
    if (!m_bSetSpeed)
    {
        m_SpeedX = dx / d * m_Speed;
        m_SpeedY = dy / d * m_Speed;
        m_bSetSpeed = true;
    }
    // 移動
    CMoveSimple::Update(px, py);
    return k_failure;
}
