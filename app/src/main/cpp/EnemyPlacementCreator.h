//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMYPLACEMENTCREATOR_H
#define ENEMYPLACEMENTCREATOR_H

#include "EnemyPlacement.h"

namespace Shooting2D
{
    class IEnemyPlacementCreator
    {
    public:
        virtual ~IEnemyPlacementCreator() = default;

        virtual MyVoid Create(CEnemyPlacement& placement) = 0;
    };
    using EnemyPlacementCreatorPtr = std::shared_ptr<IEnemyPlacementCreator>;
}

#endif //ENEMYPLACEMENTCREATOR_H
