//
// Created by akasu on 2021/10/08.
//

#ifndef SECONTROLLER_H
#define SECONTROLLER_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    template < typename Key >
    class ISEController
    {
    public:
        virtual ~ISEController() = default;

        virtual MyS32 Load(RKMy(Key) id, LPKMyS8 fileName) = 0;

        virtual MyS32 Play(RKMy(Key) id) = 0;

        virtual MyVoid SetVolume(MyFloat vol) = 0;
    };

    template < typename Key >
    using SEControllerPtr = std::shared_ptr<ISEController<Key>>;
}

#endif //SECONTROLLER_H
