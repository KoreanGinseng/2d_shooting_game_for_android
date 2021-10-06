//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETFIXEDPOINTER_H
#define TURRETFIXEDPOINTER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    class CTurretFixedPointer : public CTurretDecorator
    {
    protected:
        MyFloat m_PosX;
        MyFloat m_PosY;

    public:
        explicit CTurretFixedPointer(MyFloat px, MyFloat py)
            : CTurretDecorator()
            , m_PosX(px)
            , m_PosY(py)
        {
        }

        virtual ~CTurretFixedPointer() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETFIXEDPOINTER_H
