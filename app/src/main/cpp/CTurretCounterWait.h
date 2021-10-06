//
// Created by akasu on 2021/10/06.
//

#ifndef CTURRETCOUNTERWAIT_H
#define CTURRETCOUNTERWAIT_H

#include "TurretCounter.h"

namespace Shooting2D
{
    class CTurretCounterWait : public CTurretCounter
    {
    protected:
        MyS32 m_ResetCount;
        MyS32 m_Interval;
        MyS32 m_Wait;

    public:
        CTurretCounterWait(MyS32 count, MyS32 wait)
            : CTurretCounter()
            , m_ResetCount(count)
            , m_Interval(wait)
            , m_Wait(0)
        {
        }

        virtual ~CTurretCounterWait() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            // ウェイトの減少
            m_Wait--;
            // ウェイトがある場合待機
            if (m_Wait > 0)
            {
                return k_failure;
            }
            MyS32 result = CTurretCounter::Update(px, py);
            if (m_FireCount >= m_ResetCount)
            {
                m_FireCount = 0;
                m_Wait = m_Interval;
            }
            return result;
        }

        MyBool IsFire() const noexcept override
        {
            return (m_Wait <= 1 && m_Wait >= 0);
        }
    };
}

#endif //CTURRETCOUNTERWAIT_H
