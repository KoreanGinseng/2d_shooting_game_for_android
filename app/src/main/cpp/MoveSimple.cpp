/******************************************************************************/
/*! @file       MoveSimple.cpp
    @brief      移動クラス実装ファイル
*******************************************************************************/

#include "MoveSimple.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]  sx     移動速度X
    @param[in]  sy     移動速度Y
*******************************************************************************/
CMoveSimple::CMoveSimple(MyFloat sx, MyFloat sy)
    : m_SpeedX(sx)
    , m_SpeedY(sy)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CMoveSimple::~CMoveSimple()
{
}

/******************************************************************************/
/*! 更新
    @param[in,out]  px    移動させる座標X
    @param[in,out]  py    移動させる座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CMoveSimple::Update(MyFloat &px, MyFloat &py)
{
    px += m_SpeedX;
    py += m_SpeedY;
    return k_Success;
}