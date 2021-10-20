//
// Created by akasu on 2021/10/20.
//

#ifndef TURRETFRAMETIMER_H
#define TURRETFRAMETIMER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    class CTurretFrameTimer : public CTurretDecorator
    {
    protected:

        MyS32 m_Timer;

    public:

        explicit CTurretFrameTimer(MyS32 t)
            : m_Timer(t)
        {
        }

        virtual ~CTurretFrameTimer() override = default;

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            m_Timer--;
            if (m_Timer > 0)
            {
                return k_failure;
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETFRAMETIMER_H
