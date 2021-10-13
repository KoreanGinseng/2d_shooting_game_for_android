//
// Created by akasu on 2021/10/13.
//

#ifndef MISSIONHIDEALLENEMY_H
#define MISSIONHIDEALLENEMY_H

#include "MissionFlag.h"
#include "EnemyManager.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class CMissionHideAllEnemy : public IMissionFlag
    {
    public:
        ~CMissionHideAllEnemy() = default;

        virtual MyBool IsValid() const noexcept override
        {
            auto& enemy = CSingletonBlackboard<CEnemyManager>::GetInstance().Get<CEnemyManager>("EnemyManager");
            return enemy.IsHideAllEnemy();
        }
    };
}

#endif //MISSIONHIDEALLENEMY_H
