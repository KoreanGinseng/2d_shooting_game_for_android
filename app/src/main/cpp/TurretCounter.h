//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCOUNTER_H
#define TURRETCOUNTER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    class CTurretCounter : public CTurretDecorator
    {
    protected:
        MyS32 m_FireCount;

    public:
        CTurretCounter()
            : CTurretDecorator()
            , m_FireCount(0)
        {
        }

        virtual ~CTurretCounter() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            if (result == k_Success)
            {
                m_FireCount++;
            }
            return result;
        }
    };
}

#endif //TURRETCOUNTER_H
