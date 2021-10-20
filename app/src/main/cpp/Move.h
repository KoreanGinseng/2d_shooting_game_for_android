//
// Created by akasu on 2021/10/13.
//

#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class IMove
    {
    public:
        virtual ~IMove() = default;

        virtual MyS32 Update(MyFloat& px, MyFloat& py) = 0;

        virtual const MyFloat GetSpeedX() const noexcept = 0;

        virtual const MyFloat GetSpeedY() const noexcept = 0;
    };
    using MovePtr = std::shared_ptr<IMove>;
}

#endif //MOVE_H
