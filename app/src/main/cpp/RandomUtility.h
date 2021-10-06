//
// Created by akasu on 2021/10/06.
//

#ifndef RANDOMUTILITY_H
#define RANDOMUTILITY_H

#include "Singleton.h"
#include "RandomDevice.h"

namespace Shooting2D
{
    class CRandomUtility : public CSingleton<CRandomUtility>
    {
        friend class CSingleton<CRandomUtility>;
    private:
        RandomUniquePtr m_Random;

        CRandomUtility()
            : CSingleton()
            , m_Random(std::make_unique<CRandomDevice>())
        {
        }
    public:

        static MyS32 Random(MyS32 high)
        {
            return GetInstance().m_Random->Random(0, high);
        }

        static MyS32 Random(MyS32 low, MyS32 high)
        {
            return GetInstance().m_Random->Random(low, high);
        }

        static MyFloat RandomFloat()
        {
            return GetInstance().m_Random->Random(0, 10001) * 0.0001f;
        }
    };
}

#endif //RANDOMUTILITY_H
