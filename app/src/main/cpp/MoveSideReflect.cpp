//
// Created by akasu on 2021/10/13.
//

#include "MoveSideReflect.h"

using namespace Shooting2D;

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

CMoveSideReflect::~CMoveSideReflect()
{
}

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