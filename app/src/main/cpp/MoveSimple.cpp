//
// Created by akasu on 2021/10/13.
//

#include "MoveSimple.h"

using namespace Shooting2D;

CMoveSimple::CMoveSimple(MyFloat sx, MyFloat sy)
    : m_SpeedX(sx)
    , m_SpeedY(sy)
{
}

CMoveSimple::~CMoveSimple()
{
}

MyS32 CMoveSimple::Update(MyFloat &px, MyFloat &py)
{
    px += m_SpeedX;
    py += m_SpeedY;
    return k_Success;
}

const MyFloat CMoveSimple::GetSpeedX() const noexcept
{
    return m_SpeedX;
}

const MyFloat CMoveSimple::GetSpeedY() const noexcept
{
    return m_SpeedY;
}