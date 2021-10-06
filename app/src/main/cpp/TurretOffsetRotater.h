//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETOFFSETROTATER_H
#define TURRETOFFSETROTATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretOffsetRotater : public CTurretDecorator
    {
    protected:
        MyFloat m_Speed;

    public:
        explicit CTurretOffsetRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        virtual ~CTurretOffsetRotater() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            if (result == k_Success)
            {
                MyFloat sina = std::sinf(ToRadian(m_Speed));
                MyFloat cosa = std::cosf(ToRadian(m_Speed));
                MyFloat ox = GetOffsetX();
                MyFloat oy = GetOffsetY();
                SetOffset(ox * cosa + oy * -sina, ox * sina + oy * cosa);
            }
            return result;
        }
    };
}

#endif //TURRETOFFSETROTATER_H
