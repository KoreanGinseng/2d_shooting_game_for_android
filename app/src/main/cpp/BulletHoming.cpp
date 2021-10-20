//
// Created by akasu on 2021/10/13.
//

#include "BulletHoming.h"

using namespace Shooting2D;

CBulletHoming::CBulletHoming(GameObjectPtr target)
    : CBullet()
    , m_Target(target)
    , m_MaxSpeed(0.0f)
{
}

CBulletHoming::~CBulletHoming()
{
}

MyS32 CBulletHoming::Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img)
{
    MyS32 result = CBullet::Initialize(px, py, sx, sy, iw, ih, img);
    m_MaxSpeed = sqrtf(sx * sx + sy * sy);
    return result;
}

MyS32 CBulletHoming::Update()
{
    if (m_Target && m_Target->IsShow())
    {
        MyFloat dx = m_Target->GetPosX() - m_PosX;
        MyFloat dy = m_Target->GetPosY() - m_PosY;
        MyFloat d  = sqrtf(dx * dx + dy * dy);
        MyFloat nx = dx / d;
        MyFloat ny = dy / d;
        m_SpeedX += nx * m_MaxSpeed * 0.05f;
        m_SpeedY += ny * m_MaxSpeed * 0.05f;
        MyFloat spdd = sqrtf(m_SpeedX * m_SpeedX + m_SpeedY * m_SpeedY);
        if (spdd >= m_MaxSpeed)
        {
            m_SpeedX /= spdd;
            m_SpeedY /= spdd;
            m_SpeedX *= m_MaxSpeed;
            m_SpeedY *= m_MaxSpeed;
        }
    }
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
    }
    return CBullet::Update();
}
