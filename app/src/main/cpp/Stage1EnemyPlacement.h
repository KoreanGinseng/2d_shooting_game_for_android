//
// Created by akasu on 2021/10/06.
//

#ifndef STAGE1ENEMYPLACEMENT_H
#define STAGE1ENEMYPLACEMENT_H

#include "EnemyPlacementCreator.h"

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

            // 配置
            placement.AddAppear(100.0f, 0.0f, 100.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 200.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 300.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 400.0f, 0);
            placement.AddAppear(100.0f, 0.0f, 500.0f, 0);

            placement.AddAppear(200.0f, 0.0f, 1100.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1200.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1300.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1400.0f, 0);
            placement.AddAppear(200.0f, 0.0f, 1500.0f, 0);
        }
    };
}

#endif //STAGE1ENEMYPLACEMENT_H
