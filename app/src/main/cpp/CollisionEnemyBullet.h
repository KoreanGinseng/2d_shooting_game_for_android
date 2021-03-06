/******************************************************************************/
/*! @file       CollisionEnemyBullet.h
    @brief      敵と弾の当たり判定
*******************************************************************************/

#ifndef COLLISIONENEMYBULLET_H
#define COLLISIONENEMYBULLET_H

#include "CollisionFunction.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EffectEmitter.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! 敵と弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(CEnemy& enemy, CBullet& bullet)
    {
        // どちらかが非表示
        if (!enemy.IsShow() || !bullet.IsShow()) { return; }
        // 判定
        if (!CollisionGameObject(enemy, bullet))
        {
            // 接触なし
            return;
        }
        // 敵にダメージ
        enemy.Damage(1);
        // 弾は接触で非表示
        bullet.SetShow(false);
        // エフェクト発生
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
                .Get<EffectEmitterPtr>("Hit")->Emit(bullet.GetPosX(), bullet.GetPosY());
    }

    /******************************************************************************/
    /*! 敵と弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(CBullet& b, CEnemy& e)
    {
        Collision(e, b);
    }

    /******************************************************************************/
    /*! 敵と弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(EnemyPtr& e, BulletPtr& b)
    {
        Collision(*e, *b);
    }

    /******************************************************************************/
    /*! 敵と弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision<>(BulletPtr& b, EnemyPtr& e)
    {
        Collision(*e, *b);
    }
}

#endif //COLLISIONENEMYBULLET_H
