//
// Created by akasu on 2021/10/20.
//

#ifndef TURRETCREATORTYPE5_H
#define TURRETCREATORTYPE5_H

#include "TurretCreatorType4.h"
#include "TurretFrameTimer.h"

namespace Shooting2D
{
    class CTurretCreatorType5 : public CTurretCreatorType4
    {
    protected:

        MyS32 m_Timer;

    public:
        explicit CTurretCreatorType5(
                RKMyString list, MyFloat offx, MyFloat offy,
                MyFloat sx, MyFloat sy, MyS32 wait, MyInt img, MyS32 t
                )
            : CTurretCreatorType4(list, offx, offy, sx, sy, wait, img)
            , m_Timer(t)
        {
        }

        virtual ~CTurretCreatorType5() override = default;

        virtual TurretPtr Create() override
        {
            return CTurretCreatorType4::Create()->Decorate<CTurretFrameTimer>(m_Timer);
        }
    };
}

#endif //TURRETCREATORTYPE5_H
