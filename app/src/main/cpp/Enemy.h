//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

namespace Shooting2D
{
    class CEnemy : public CGameObject
    {
    private:
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

        MyFloat m_Angle;

        MyInt m_Image;

    public:
        CEnemy();
        virtual ~CEnemy() override;

        MyS32 Initialize(MyFloat px, MyFloat py, MyInt img);

        MyS32 Update() override;

        MyS32 Draw() override;
    };
    using EnemyPtr = std::shared_ptr<CEnemy>;
    using EnemyList = std::list<EnemyPtr>;
}

#endif //ENEMY_H
