//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "TurretCreator.h"
#include "MoveCreator.h"

namespace Shooting2D
{
    class CEnemy : public CGameObject
    {
    private:
        MyS32   m_HP;

        MyFloat m_Angle;

        MyInt   m_Image;

        TurretPtr m_Turret;

        MovePtr m_Move;

    public:
        CEnemy();
        virtual ~CEnemy() override;

        MyS32 Initialize(MyFloat px, MyFloat py, MyInt img, TurretCreatorPtr tcp, MoveCreatorPtr mcp);

        MyS32 Update() override;

        MyS32 Draw() override;

        MyVoid Damage(MyS32 dmg);

        MyS32 GetHP() const noexcept;
    };
    using EnemyPtr  = std::shared_ptr<CEnemy>;
    using EnemyList = std::list<EnemyPtr>;
}

#endif //ENEMY_H
