//
// Created by akasu on 2021/10/06.
//

#ifndef COLLISIONPLAYERENEMY_H
#define COLLISIONPLAYERENEMY_H

#include "CollisionFunction.h"
#include "Player.h"
#include "Enemy.h"

namespace Shooting2D
{
    template < >
    inline MyVoid CCollisionFunction::Collision<>(CPlayer& player, CEnemy& enemy)
    {
        // どちらかが非表示
        if (!player.IsShow() || !enemy.IsShow()) { return; }
        // 判定
        if (!CollisionGameObject(player, enemy))
        {
            // 接触なし
            return;
        }
        // プレイヤーを非表示にする
        player.SetShow(false);
    }

    template < >
    inline MyVoid CCollisionFunction::Collision<>(CEnemy& e, CPlayer& p)
    {
        Collision(p, e);
    }

    template < >
    inline MyVoid CCollisionFunction::Collision<>(CPlayer& p, EnemyPtr& e)
    {
        Collision(p, *e);
    }

    template < >
    inline MyVoid CCollisionFunction::Collision<>(EnemyPtr& e, CPlayer& p)
    {
        Collision(p, *e);
    }
}

#endif //COLLISIONPLAYERENEMY_H