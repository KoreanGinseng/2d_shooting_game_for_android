//
// Created by akasu on 2021/10/06.
//

#include "TurretArray.h"

using namespace Shooting2D;

CTurretArray::CTurretArray()
    : m_TurretArray()
{
}

CTurretArray::~CTurretArray()
{
}

MyS32 CTurretArray::Update(MyFloat px, MyFloat py)
{
    for (auto& turret : m_TurretArray)
    {
        turret->Update(px, py);
    }
    return k_Success;
}

MyFloat CTurretArray::GetOffsetX() const noexcept
{
    return m_TurretArray[0]->GetOffsetX();
}

MyFloat CTurretArray::GetOffsetY() const noexcept
{
    return m_TurretArray[0]->GetOffsetY();
}

MyFloat CTurretArray::GetSpeedX() const noexcept
{
    return m_TurretArray[0]->GetSpeedX();
}

MyFloat CTurretArray::GetSpeedY() const noexcept
{
    return m_TurretArray[0]->GetSpeedY();
}

MyVoid CTurretArray::SetOffset(MyFloat sx, MyFloat sy)
{
    for (auto& turret : m_TurretArray)
    {
        turret->SetOffset(sx, sy);
    }
}

MyVoid CTurretArray::SetSpeed(MyFloat sx, MyFloat sy)
{
    for (auto& turret : m_TurretArray)
    {
        turret->SetSpeed(sx, sy);
    }
}

MyBool CTurretArray::IsFire() const noexcept
{
    return m_TurretArray[0]->IsFire();
}