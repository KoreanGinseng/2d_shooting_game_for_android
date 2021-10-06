//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETRANDOMPOINTER_H
#define TURRETRANDOMPOINTER_H

#include "TurretDecorator.h"
#include "RandomUtility.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretRandomPointer : public CTurretDecorator
    {
    protected:
        MyFloat m_AreaLeft;
        MyFloat m_AreaTop;
        MyFloat m_AreaRight;
        MyFloat m_AreaBottom;

        MyFloat m_PosX;
        MyFloat m_PosY;

    public:
        explicit CTurretRandomPointer(MyFloat l, MyFloat t, MyFloat r, MyFloat b)
            : m_AreaLeft(l)
            , m_AreaTop(t)
            , m_AreaRight(r)
            , m_AreaBottom(b)
            , m_PosX(0.0f)
            , m_PosY(0.0f)
        {
        }

        virtual ~CTurretRandomPointer() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            if (IsFire())
            {
                MyFloat randX = CRandomUtility::RandomFloat();
                MyFloat randY = CRandomUtility::RandomFloat();
                m_PosX = m_AreaLeft + (m_AreaRight - m_AreaLeft) * randX;
                m_PosY = m_AreaTop + (m_AreaBottom - m_AreaTop) * randY;
            }
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETRANDOMPOINTER_H
