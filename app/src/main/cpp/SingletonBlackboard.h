//
// Created by akasu on 2021/10/05.
//

#ifndef SINGLETONBLACKBOARD_H
#define SINGLETONBLACKBOARD_H

#include "Blackboard.h"
#include "Singleton.h"

namespace Shooting2D
{
    template < typename... Types >
    class CSingletonBlackboard : public CSingleton<CBlackboard<Types...>>
    {
        friend class CSingleton<CBlackboard<Types...>>;
    };
}

#endif //SINGLETONBLACKBOARD_H
