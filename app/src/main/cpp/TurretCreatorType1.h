//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCREATORTYPE1_H
#define TURRETCREATORTYPE1_H

#include "TurretCreator.h"
#include "TurretSimple.h"
#include "TurretRotater.h"
#include "TurretContinuous.h"
#include "TurretWait.h"

namespace Shooting2D
{
    class CTurretCreatorType1 : public ITurretCreator
    {
    protected:
        std::string m_ListName;
        MyFloat m_OffsetX;
        MyFloat m_OffsetY;
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;
        MyS32 m_Interval;
        MyInt m_BulletImage;

    public:
        explicit CTurretCreatorType1(
                RKMyString list, MyFloat offx, MyFloat offy,
                MyFloat sx, MyFloat sy, MyS32 wait, MyInt img
                )
            : m_ListName(list)
            , m_OffsetX(offx)
            , m_OffsetY(offy)
            , m_SpeedX(sx)
            , m_SpeedY(sy)
            , m_Interval(wait)
            , m_BulletImage(img)
        {
        }

        virtual ~CTurretCreatorType1() override = default;

        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretSimple>(m_ListName,
                    m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY,
                    m_Interval, m_BulletImage)
                    ->Decorate<CTurretRotater>(36.0f)
                    ->Decorate<CTurretContinuous>(10)
                    ->Decorate<CTurretWait>(10);
        }
    };
}

#endif //TURRETCREATORTYPE1_H
