//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETRANDOMROTATER_H
#define TURRETRANDOMROTATER_H

#include "TurretDecorator.h"
#include "RandomUtility.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretRandomRotater : public CTurretDecorator
    {
    protected:
        MyFloat m_Speed;

    public:
        explicit CTurretRandomRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        virtual ~CTurretRandomRotater() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            if (IsFire())
            {
                MyFloat p = (CRandomUtility::RandomFloat() * 2.0f) - 1;
                MyFloat sina = std::sinf(ToRadian(m_Speed * p));
                MyFloat cosa = std::cosf(ToRadian(m_Speed * p));
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * cosa + vy * -sina, vx * sina + vy * cosa);
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETRANDOMROTATER_H
