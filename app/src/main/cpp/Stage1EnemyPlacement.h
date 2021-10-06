//
// Created by akasu on 2021/10/06.
//

#ifndef STAGE1ENEMYPLACEMENT_H
#define STAGE1ENEMYPLACEMENT_H

#include "EnemyPlacementCreator.h"
#include "TurretCreatorType1.h"
#include "TurretCreatorType2.h"
#include "TurretCreatorType3.h"

namespace Shooting2D
{
    class CStage1EnemyPlacement : public IEnemyPlacementCreator
    {
    public:
        CStage1EnemyPlacement() = default;
        virtual ~CStage1EnemyPlacement() override = default;

        MyVoid Create(CEnemyPlacement& placement) override
        {
            // 画像の読み込み
            placement.AddImage("image/Enemy/Enemy01.png");
            placement.AddImage("image/Enemy/Enemy05.png");
            placement.AddImage("image/Enemy/Enemy08.png");
            placement.AddBulletImage("image/Bullets/02Bullets.png");
            placement.AddBulletImage("image/Bullets/01Bullets.png");
            placement.AddBulletImage("image/Bullets/04Bullets.png");

            // 弾パターンの登録
            placement.AddTurretPattern(
                    std::make_shared<CTurretCreatorType1>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(0)
                            )
                    );
            placement.AddTurretPattern(
                    std::make_shared<CTurretCreatorType2>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(1)
                            )
                    );
            placement.AddTurretPattern(
                    std::make_shared<CTurretCreatorType3>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(2)
                            )
                    );

            // 配置
            placement.AddAppear(100.0f, 0.0f, 100.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 200.0f, 1);
            placement.AddAppear(100.0f, 0.0f, 300.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 400.0f, 1);
            placement.AddAppear(100.0f, 0.0f, 500.0f, 0);

            placement.AddAppear(200.0f, 0.0f, 1100.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1200.0f, 2);
            placement.AddAppear(200.0f, 0.0f, 1300.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1400.0f, 2);
            placement.AddAppear(200.0f, 0.0f, 1500.0f, 0);
        }
    };
}

#endif //STAGE1ENEMYPLACEMENT_H
