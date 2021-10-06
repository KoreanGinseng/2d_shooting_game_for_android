//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Enemy.h"
#include "EnemyPlacementCreator.h"

namespace Shooting2D
{
    class CEnemyManager
    {
    private:
        size_t          m_CurrentAppear;
        EnemyList       m_EnemyList;
        CEnemyPlacement m_Placement;
    public:
        CEnemyManager();
        ~CEnemyManager();

        MyS32 Load(EnemyPlacementCreatorPtr epc);

        MyS32 Initialize();

        MyS32 Update(MyFloat scroll);

        MyS32 Draw();

        MyS32 Release();

        EnemyList& GetEnemyList();

    };
}


#endif //TEST_ENEMYMANAGER_H
