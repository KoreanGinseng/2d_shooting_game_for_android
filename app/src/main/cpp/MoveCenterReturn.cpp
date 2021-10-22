/******************************************************************************/
/*! @file       MoveCenterReturn.cpp
    @brief      移動クラス実装ファイル
*******************************************************************************/

#include "MoveCenterReturn.h"
#include "GameDefine.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]  sx     移動速度X
    @param[in]  sy     移動速度Y
    @param[in]  tsx    折り返し移動速度X
*******************************************************************************/
CMoveCenterReturn::CMoveCenterReturn(MyFloat sx, MyFloat sy, MyFloat tsx)
     : CMoveSimple(sx, sy)
     , m_TurnSpeedX(tsx)
     , m_bTurn(false)
{
};

/******************************************************************************/
/*! 更新
    @param[in,out]  px    移動させる座標X
    @param[in,out]  py    移動させる座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
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
        // 自分のいる位置から反転して帰っていく
        if (px < k_SceneWidth * 0.5f)
        {
            if (m_TurnSpeedX < 0)
            {
                m_TurnSpeedX = -m_TurnSpeedX;
            }
        }
        else
        {
            if (m_TurnSpeedX > 0)
            {
                m_TurnSpeedX = -m_TurnSpeedX;
            }
        }
    }
    px += m_TurnSpeedX;
    py -= m_SpeedY;
    return k_Success;
}