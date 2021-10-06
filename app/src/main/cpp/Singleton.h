//
// Created by akasu on 2021/10/05.
//

#ifndef SINGLETON_H
#define SINGLETON_H

#include "Common.h"
#include <cassert>

namespace Shooting2D
{
    template < typename T >
    class CSingleton
    {
    private:
        CSingleton(RKMy(CSingleton)) = delete;
        CSingleton(CSingleton&&) = delete;

        static T* m_Instance;

    protected:
        CSingleton() {}
        virtual ~CSingleton() {}

        static MyVoid Create()
        {
            assert(!m_Instance);
            if (m_Instance)
            {
                return;
            }
            m_Instance = new T();
        }

    public:

        static constexpr T& GetInstance()
        {
            if (m_Instance == nullptr)
            {
                Create();
            }
            return *m_Instance;
        }

        static MyVoid Release()
        {
            assert(m_Instance);
            if (m_Instance)
            {
                delete m_Instance;
                m_Instance = nullptr;
                return;
            }
        }
    };
    template < typename T >
    T* CSingleton<T>::m_Instance = nullptr;
}

#endif //SINGLETON_H
