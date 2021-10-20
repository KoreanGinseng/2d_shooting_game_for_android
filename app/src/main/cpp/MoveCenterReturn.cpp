//
// Created by akasu on 2021/10/20.
//

#include "MoveCenterReturn.h"
#include "GameDefine.h"

using namespace Shooting2D;

CMoveCenterReturn::CMoveCenterReturn(MyFloat sx, MyFloat sy, MyFloat tsx)
     : CMoveSimple(sx, sy)
     , m_TurnSpeedX(tsx)
     , m_bTurn(false)
{
};

MyS32 CMoveCenterReturn::Update(MyFloat &px, MyFloat &py)
{
    // 画面半分までは直進する
    if (!m_bTurn && py <= k_SceneHeight * 0.5f)
    {
        py += m_SpeedY;
        return k_Success;
    }
    if (!m_bTurn)
    {
        m_bTurn = true;
        // 移動速度X
        m_TurnSpeedX = m_SpeedX;
        // 自分のいる位置から反転して帰っていく
        if (px < k_SceneWidth * 0.5f)
        {
            if (m_TurnSpeedX < 0)
            {
                m_TurnSpeedX = -m_SpeedX;
            }
        }
        else
        {
            if (m_TurnSpeedX > 0)
            {
                m_TurnSpeedX = -m_SpeedX;
            }
        }
    }
    px += m_TurnSpeedX;
    py -= m_SpeedY;
    return k_Success;
}