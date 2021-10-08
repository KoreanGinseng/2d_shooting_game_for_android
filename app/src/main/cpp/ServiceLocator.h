//
// Created by akasu on 2021/10/08.
//

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#include <memory>
#include "Singleton.h"

namespace Shooting2D
{
    template < typename T >
    class CServiceLocator : public CSingleton<CServiceLocator<T>>
    {
        friend class CSingleton<CServiceLocator<T>>;
        using Service = std::shared_ptr<T>;

    protected:
        Service m_Service;

        CServiceLocator()
            : m_Service()
        {
        }

    public:
        static MyVoid SetService(RKMy(Service) obj) noexcept
        {
            CServiceLocator<T>::GetInstance().m_Service = obj;
        }

        static Service& GetService() noexcept
        {
            return CServiceLocator<T>::GetInstance().m_Service;
        }

    };
}

#endif //SERVICELOCATOR_H
