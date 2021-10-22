/******************************************************************************/
/*! @file       Stage1EnemyPlacement.h
    @brief      ステージ１の敵配置情報クラス定義ファイル
*******************************************************************************/

#ifndef STAGE1ENEMYPLACEMENT_H
#define STAGE1ENEMYPLACEMENT_H

#include "EnemyPlacementCreator.h"
#include "TurretCreatorType1.h"
#include "TurretCreatorType2.h"
#include "TurretCreatorType3.h"
#include "TurretCreatorType4.h"
#include "TurretCreatorType5.h"
#include "TurretCreatorTypeStraight.h"
#include "MoveCreatorType1.h"
#include "MoveCreatorType2.h"
#include "MoveCreatorType3.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CStage1EnemyPlacement
        @brief  ステージ１敵情報生成クラス
    *******************************************************************************/
    class CStage1EnemyPlacement : public IEnemyPlacementCreator
    {
    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CStage1EnemyPlacement() = default;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CStage1EnemyPlacement() override = default;

        /******************************************************************************/
        /*! 敵配置の生成
            @param[in]      placement    敵配置情報
        *******************************************************************************/
        MyVoid Create(CEnemyPlacement& placement) override
        {
            // 画像の読み込み
            placement.AddImage("image/Enemy/Enemy01.png");
            placement.AddImage("image/Enemy/Enemy05.png");
            placement.AddImage("image/Enemy/Enemy08.png");
            placement.AddImage("image/Enemy/Enemy13.png");
            placement.AddImage("image/Enemy/Enemy06.png");
            placement.AddBulletImage("image/Bullets/02Bullets.png");
            placement.AddBulletImage("image/Bullets/01Bullets.png");
            placement.AddBulletImage("image/Bullets/04Bullets.png");
            placement.AddBulletImage("image/Bullets/08Bullets.png");
            placement.AddBulletImage("image/Bullets/03Bullets.png");

            // 弾パターンの登録
            placement.AddTurretPattern( // 乱射１
                    std::make_shared<CTurretCreatorType2>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(1)
                    )
            );
            placement.AddTurretPattern( // 乱射２
                    std::make_shared<CTurretCreatorType1>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(0)
                            )
                    );
            placement.AddTurretPattern( // 待機してから標的へ発射
                    std::make_shared<CTurretCreatorType5>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 20,
                            placement.GetBulletImage(4), 240
                            )
                    );
            placement.AddTurretPattern( // まっすぐ発射
                    std::make_shared<CTurretCreatorTypeStraight>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 20,
                            placement.GetBulletImage(3)
                            )
                    );
            placement.AddTurretPattern( // 標的へ発射
                    std::make_shared<CTurretCreatorType4>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 20,
                            placement.GetBulletImage(4)
                            )
                    );
            placement.AddTurretPattern( // 標的へ乱射
                    std::make_shared<CTurretCreatorType3>(
                            "EnemyBullet",
                            0.0f, 0.0f, 0.0f, 5.0f, 0,
                            placement.GetBulletImage(2)
                    )
            );
            // 移動パターンの登録
            placement.AddMovePattern( // 直進
                    std::make_shared<CMoveCreatorType1>(
                            0.0f, 2.0f
                            )
                    );
            placement.AddMovePattern( // ジグザグ移動
                    std::make_shared<CMoveCreatorType2>(
                            1.0f, 2.0f, 200.0f, 200.0f
                            )
                    );
            placement.AddMovePattern( // 中央で折り返し移動
                    std::make_shared<CMoveCreatorType3>(
                            0.0f, 2.0f, 2.0f
                            )
                    );
            placement.AddMovePattern( // ジグザグ移動
                    std::make_shared<CMoveCreatorType2>(
                            1.0f, 2.0f, 100.0f, 100.0f
                            )
                    );
            placement.AddMovePattern( // 直進
                    std::make_shared<CMoveCreatorType1>(
                            0.0f, 2.0f
                            )
                    );

            // 配置
            placement.AddAppear(120.0f, 0.0f, 100.0f, 3);
            placement.AddAppear(120.0f, 0.0f, 200.0f, 3);
            placement.AddAppear(120.0f, 0.0f, 300.0f, 3);
            placement.AddAppear(120.0f, 0.0f, 400.0f, 3);
            placement.AddAppear(120.0f, 0.0f, 500.0f, 3);

            placement.AddAppear(120.0f, 0.0f, 600.0f, 4);
            placement.AddAppear(200.0f, 0.0f, 700.0f, 4);
            placement.AddAppear(120.0f, 0.0f, 800.0f, 4);
            placement.AddAppear(200.0f, 0.0f, 900.0f, 4);
            placement.AddAppear(120.0f, 0.0f, 1000.0f, 4);

            placement.AddAppear(200.0f, 0.0f, 1100.0f, 2);
            placement.AddAppear(340.0f, 0.0f, 1200.0f, 2);
            placement.AddAppear(200.0f, 0.0f, 1300.0f, 2);
            placement.AddAppear(340.0f, 0.0f, 1400.0f, 2);
            placement.AddAppear(200.0f, 0.0f, 1500.0f, 2);

            placement.AddAppear(200.0f, 0.0f, 1700.0f, 1);
            placement.AddAppear(200.0f, 0.0f, 1720.0f, 1);
            placement.AddAppear(200.0f, 0.0f, 1740.0f, 1);
            placement.AddAppear(200.0f, 0.0f, 1760.0f, 1);

            placement.AddAppear(340.0f, 0.0f, 2000.0f, 1);
            placement.AddAppear(340.0f, 0.0f, 2020.0f, 1);
            placement.AddAppear(340.0f, 0.0f, 2040.0f, 1);
            placement.AddAppear(340.0f, 0.0f, 2060.0f, 1);
        }
    };
}

#endif //STAGE1ENEMYPLACEMENT_H
