//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETWAIT_H
#define TURRETWAIT_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    class CTurretWait : public CTurretDecorator
    {
    protected:
        MyS32 m_Interval;
        MyS32 m_Wait;

    public:
        explicit CTurretWait(MyS32 count)
            : CTurretDecorator()
            , m_Interval(count)
            , m_Wait(count)
        {
        }

        virtual ~CTurretWait() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            // ウェイトの減少
            m_Wait--;
            if (m_Wait > 0)
            {
                return k_failure;
            }
            // 次の発射までのウェイトを設定
            m_Wait = m_Interval;
            // 発射
            return CTurretDecorator::Update(px, py);
        }

        virtual MyBool IsFire() const noexcept override
        {
            return (m_Wait <= 1 && m_Turret->IsFire());
        }
    };
}

#endif //TURRETWAIT_H
