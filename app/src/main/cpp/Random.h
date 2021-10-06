//
// Created by akasu on 2021/10/06.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <cassert>
#include <random>
#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class IRandom
    {
    public:
        virtual ~IRandom() = default;
        virtual MyS32 Random(MyS32 low, MyS32 high) = 0;
        virtual MyVoid ResetSeed() = 0;
    };
    using RandomPtr = std::shared_ptr<IRandom>;
    using RandomUniquePtr = std::unique_ptr<IRandom>;
}

#endif //RANDOM_H
