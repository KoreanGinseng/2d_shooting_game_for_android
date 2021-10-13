//
// Created by akasu on 2021/10/13.
//

#ifndef MISSIONFLAG_H
#define MISSIONFLAG_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class IMissionFlag
    {
    public:
        virtual ~IMissionFlag() = default;

        virtual MyBool IsValid() const noexcept = 0;
    };
    using MissionFlagPtr = std::shared_ptr<IMissionFlag>;
}

#endif //MISSIONFLAG_H
