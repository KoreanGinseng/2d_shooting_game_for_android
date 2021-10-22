/******************************************************************************/
/*! @file       CollisionPlayerBullet.h
    @brief      プレイヤーと敵弾の当たり判定
*******************************************************************************/

#ifndef COLLISIONPLAYERBULLET_H
#define COLLISIONPLAYERBULLET_H

#include "CollisionFunction.h"
#include "Player.h"
#include "Enemy.h"
#include "EffectEmitter.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! プレイヤーと敵弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision(CPlayer& player, CBullet& bullet)
    {
        // どちらかが非表示
        if (!player.IsShow() || !bullet.IsShow()) { return; }
        // 判定
        if (!CollisionGameObject(player, bullet))
        {
            // 接触なし
            return;
        }
        // プレイヤーを非表示にする
        player.SetShow(false);
        // 弾は接触で非表示
        bullet.SetShow(false);
        // エフェクト発生
        CSingletonBlackboard<EffectEmitterPtr>::GetInstance()
        .Get<EffectEmitterPtr>("Explosion")->Emit(player.GetPosX(), player.GetPosY());
    }

    /******************************************************************************/
    /*! プレイヤーと敵弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision(CBullet& b, CPlayer& p)
    {
        Collision(p, b);
    }

    /******************************************************************************/
    /*! プレイヤーと敵弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision(CPlayer& p, BulletPtr& b)
    {
        Collision(p, *b);
    }

    /******************************************************************************/
    /*! プレイヤーと敵弾の当たり判定
    *******************************************************************************/
    template < >
    inline MyVoid CCollisionFunction::Collision(BulletPtr& b, CPlayer& p)
    {
        Collision(p, *b);
    }
}

#endif //COLLISIONPLAYERBULLET_H
