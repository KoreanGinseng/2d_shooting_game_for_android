//
// Created by akasu on 2021/10/09.
//

#ifndef EFFECTEMITTER_H
#define EFFECTEMITTER_H

#include "Effect.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class IEffectEmitter
    {
    protected:
        virtual MyS32 Create(MyInt bimg) = 0;

    public:
        virtual ~IEffectEmitter() = default;

        virtual EffectPtr Emit(MyFloat px, MyFloat py) = 0;
    };

    using EffectEmitterPtr = std::shared_ptr<IEffectEmitter>;
    using EffectEmitterArray = std::vector<EffectEmitterPtr>;
}

#endif //EFFECTEMITTER_H
