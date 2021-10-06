//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETACCELERATOR_H
#define TURRETACCELERATOR_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretAccelerator : public CTurretDecorator
    {
    protected:
        MyFloat m_Speed;

    public:
        explicit CTurretAccelerator(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        virtual ~CTurretAccelerator() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            // 発射したら加速実行
            if (result == k_Success)
            {
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * m_Speed, vy * m_Speed);
            }
            return result;
        }
    };
}

#endif //TURRETACCELERATOR_H
