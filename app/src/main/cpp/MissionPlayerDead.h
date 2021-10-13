//
// Created by akasu on 2021/10/13.
//

#ifndef MISSIONPLAYERDEAD_H
#define MISSIONPLAYERDEAD_H

#include "MissionFlag.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class CMissionPlayerDead : public IMissionFlag
    {
    public:
        virtual ~CMissionPlayerDead() override = default;

        virtual MyBool IsValid() const noexcept override
        {
            CPlayer& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
            return !player.IsShow();
        }
    };
}

#endif //MISSIONPLAYERDEAD_H
