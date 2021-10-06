//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETROTATER_H
#define TURRETROTATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretRotater : public CTurretDecorator
    {
    protected:
        /*! 弾の回転量 */
        MyFloat m_Speed;
    public:
        explicit CTurretRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        virtual ~CTurretRotater() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            // 発射したら回転実行
            if (result == k_Success)
            {
                MyFloat sina = std::sinf(ToRadian(m_Speed));
                MyFloat cosa = std::cosf(ToRadian(m_Speed));
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * cosa + vy * -sina, vx * sina + vy * cosa);
            }
            return result;
        }
    };
}

#endif //TURRETROTATER_H
