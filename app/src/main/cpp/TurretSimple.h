//
// Created by akasu on 2021/10/05.
//

#ifndef TURRETSIMPLE_H
#define TURRETSIMPLE_H

#include "Turret.h"

namespace Shooting2D
{
    class CTurretSimple : public ITurret
    {
    protected:
        std::string m_listName;

        MyFloat m_OffsetX;
        MyFloat m_OffsetY;
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

        MyS32 m_Interval;
        MyS32 m_Wait;

        MyS32 m_ImageWidth;
        MyS32 m_ImageHeight;

        MyInt m_BulletImage;

    public:

        CTurretSimple(RKMyString list, MyFloat offx, MyFloat offy, MyFloat sx, MyFloat sy, MyS32 wait, MyInt img);

        virtual ~CTurretSimple() override;

        virtual MyS32 Initialize() override;

        virtual MyS32 Update(MyFloat px, MyFloat py) override;

        virtual MyFloat GetOffsetX() const noexcept override;
        virtual MyFloat GetOffsetY() const noexcept override;
        virtual MyFloat GetSpeedX() const noexcept override;
        virtual MyFloat GetSpeedY() const noexcept override;
        virtual MyVoid SetOffset(MyFloat sx, MyFloat sy) override;
        virtual MyVoid SetSpeed(MyFloat sx, MyFloat sy) override;
        virtual MyBool IsFire() const noexcept override;
    };
}

#endif //TURRETSIMPLE_H
