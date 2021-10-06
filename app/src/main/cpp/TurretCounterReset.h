//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCOUNTERRESET_H
#define TURRETCOUNTERRESET_H

#include "TurretCounter.h"

namespace Shooting2D
{
    class CTurretCounterReset : public CTurretCounter
    {
    protected:

        MyS32 m_ResetCount;

        MyFloat m_OffsetX;
        MyFloat m_OffsetY;
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;
    public:
        CTurretCounterReset(MyS32 count)
            : CTurretCounter()
            , m_ResetCount(count)
            , m_OffsetX(0.0f)
            , m_OffsetY(0.0f)
            , m_SpeedX(0.0f)
            , m_SpeedY(0.0f)
        {
        }

        virtual ~CTurretCounterReset() override
        {
        }

        virtual MyS32 Initialize() override
        {
            m_FireCount = 0;
            m_Turret->SetOffset(m_OffsetX, m_OffsetY);
            m_Turret->SetSpeed(m_SpeedX, m_SpeedY);
            return m_Turret->Initialize();
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretCounter::Update(px, py);
            if (m_FireCount >= m_ResetCount)
            {
                m_FireCount = 0;
                m_Turret->SetOffset(m_OffsetX, m_OffsetY);
                m_Turret->SetSpeed(m_SpeedX, m_SpeedY);
            }
            return result;
        }

        MyVoid SetTurret(TurretPtr obj) override
        {
            m_Turret = obj;
            m_OffsetX = m_Turret->GetOffsetX();
            m_OffsetY = m_Turret->GetOffsetY();
            m_SpeedX = m_Turret->GetSpeedX();
            m_SpeedY = m_Turret->GetSpeedY();
        }
    };
}

#endif //TURRETCOUNTERRESET_H
