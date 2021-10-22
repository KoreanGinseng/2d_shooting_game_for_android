/******************************************************************************/
/*! @file       CollisionPlayerEnemy.h
    @brief      プレイヤーと敵の当たり判定定義ファイル
*******************************************************************************/

#ifndef COLLISIONPLAYERENEMY_H
#define COLLISIONPLAYERENEMY_H

#include "CollisionFunction.h"
#include "Player.h"
#include "Enemy.h"
#include "EffectEmitter.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! プレイヤーと敵の当たり判定
    *******************************************************************************/
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
        // エフェクト発生
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
                .Get<EffectEmitterPtr>("Explosion")->Emit(player.GetPosX(), player.GetPosY());
    }

    /******************************************************************************/
    /*! プレイヤーと敵の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(CEnemy& e, CPlayer& p)
    {
        Collision(p, e);
    }

    /******************************************************************************/
    /*! プレイヤーと敵の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(CPlayer& p, EnemyPtr& e)
    {
        Collision(p, *e);
    }

    /******************************************************************************/
    /*! プレイヤーと敵の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(EnemyPtr& e, CPlayer& p)
    {
        Collision(p, *e);
    }
}

#endif //COLLISIONPLAYERENEMY_H
