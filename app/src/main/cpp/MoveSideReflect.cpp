/******************************************************************************/
/*! @file       MoveSideReflect.cpp
    @brief      移動クラス実装ファイル
*******************************************************************************/

#include "MoveSideReflect.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]  sx     移動速度X
    @param[in]  sy     移動速度Y
    @param[in]  rl     反射座標L
    @param[in]  rr     反射座標R
*******************************************************************************/
CMoveSideReflect::CMoveSideReflect(MyFloat sx, MyFloat sy, MyFloat rl, MyFloat rr)
    : CMoveSimple(sx, sy)
    , m_ReflectLeft(rl)
    , m_ReflectRight(rr)
    , m_bReflect(false)
    , m_OffsetX(-1.0f)
{
    if (m_ReflectRight < m_ReflectLeft)
    {
        MyFloat tmp = m_ReflectRight;
        m_ReflectRight = m_ReflectLeft;
        m_ReflectLeft = tmp;
    }
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CMoveSideReflect::~CMoveSideReflect()
{
}

/******************************************************************************/
/*! 更新
    @param[in,out]  px    移動させる座標X
    @param[in,out]  py    移動させる座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CMoveSideReflect::Update(MyFloat &px, MyFloat &py)
{
    if (m_OffsetX < 0.0f)
    {
        m_OffsetX = px;
    }
    if (CMoveSimple::Update(px, py) == k_Success)
    {
        if (!m_bReflect)
        {
            if (px <= m_OffsetX - m_ReflectLeft || px >= m_OffsetX + m_ReflectRight)
            {
                m_SpeedX *= -1;
                m_bReflect = true;
            }
        }
        else
        {
            if (px > m_OffsetX - m_ReflectLeft && px < m_OffsetX + m_ReflectRight)
            {
                m_bReflect = false;
            }
        }
    }
    return k_Success;
}