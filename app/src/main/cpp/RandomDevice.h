//
// Created by akasu on 2021/10/06.
//

#ifndef RANDOMDEVICE_H
#define RANDOMDEVICE_H

#include "Random.h"

namespace Shooting2D
{
    class CRandomDevice : public IRandom
    {
    private:
        std::random_device m_Device;

        std::mt19937       m_MersenneTwister;

    public:
        CRandomDevice()
             : m_Device()
             , m_MersenneTwister(m_Device())
        {
        }

        virtual MyS32 Random(MyS32 low, MyS32 high) override
        {
            assert(low < high);
            thread_local std::uniform_int_distribution<int> d(low, high);
            return d(m_MersenneTwister);
        }

        virtual MyVoid ResetSeed() override
        {
            m_MersenneTwister.seed(m_Device());
        }
    };
}

#endif //RANDOMDEVICE_H
