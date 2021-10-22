/******************************************************************************/
/*! @file       MoveDeadOrAlive.cpp
    @brief      死ぬまで生きてる移動クラス実装ファイル
*******************************************************************************/

#include "MoveDeadOrAlive.h"
#include "MoveSideReflect.h"
#include "MoveTarget.h"
#include "GameDefine.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]  sx     移動速度X
    @param[in]  sy     移動速度Y
    @param[in]  px     降下ポジションY
*******************************************************************************/
CMoveDeadOrAlive::CMoveDeadOrAlive(MyFloat sx, MyFloat sy, MyFloat py)
    : CMoveSimple(sx, sy)
    , m_StopPosY(py)
    , m_MoveCount(0)
    , m_FrameCount(0)
    , m_Move{
            std::make_shared<CMoveSideReflect>(m_SpeedX, 0, k_SceneWidth * 0.4f, k_SceneWidth * 0.4f),
            std::make_shared<CMoveSimple>(0, 0) }
{
}

/******************************************************************************/
/*! 更新
    @param[in,out]  px    移動させる座標X
    @param[in,out]  py    移動させる座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CMoveDeadOrAlive::Update(MyFloat &px, MyFloat &py)
{
    // 降下地点までは直線的に降りる
    if (py <= m_StopPosY)
    {
        py += m_SpeedY;
        return k_Success;
    }
    // 各移動開始
    MyS32 result = m_Move[m_MoveCount]->Update(px, py);
    m_FrameCount++;
    if (result == k_Success && m_FrameCount > 400)
    {
        m_FrameCount = 0;
        m_MoveCount++;
        if (m_MoveCount >= 2)
        {
            m_MoveCount = 0;
        }
    }
    return k_Success;
}
