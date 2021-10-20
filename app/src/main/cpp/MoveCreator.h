//
// Created by akasu on 2021/10/13.
//

#ifndef MOVECREATOR_H
#define MOVECREATOR_H

#include "Move.h"

namespace Shooting2D
{
    class IMoveCreator
    {
    public:
        virtual ~IMoveCreator() = default;

        virtual MovePtr Create() = 0;
    };
    using MoveCreatorPtr = std::shared_ptr<IMoveCreator>;
}

#endif //MOVECREATOR_H
