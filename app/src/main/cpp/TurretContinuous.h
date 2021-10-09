//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCONTINUOUS_H
#define TURRETCONTINUOUS_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    class CTurretContinuous : public CTurretDecorator
    {
    protected:
        MyS32 m_Count;

    public:
        CTurretContinuous(MyS32 count)
            : CTurretDecorator()
            , m_Count(count)
        {
        }

        virtual ~CTurretContinuous() override
        {
        }

        MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = k_failure;
            for (MyS32 i = 0; i < m_Count; i++)
            {
                result |= CTurretDecorator::Update(px, py);
            }
            return result;
        }
    };
}

#endif //TURRETCONTINUOUS_H
