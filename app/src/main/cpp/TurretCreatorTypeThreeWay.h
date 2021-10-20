//
// Created by akasu on 2021/10/13.
//

#ifndef TURRETCREATORTYPETHREEWAY_H
#define TURRETCREATORTYPETHREEWAY_H

#include "TurretCreatorType1.h"
#include "TurretArray.h"

namespace Shooting2D
{
    class CTurretCreatorTypeThreeWay : public CTurretCreatorType1
    {
    protected:

    public:
        using CTurretCreatorType1::CTurretCreatorType1;

        virtual ~CTurretCreatorTypeThreeWay() override = default;

        virtual TurretPtr Create() override
        {
            auto turretArray = std::make_shared<CTurretArray>();
            // 3発同時発射
            // 弾の発射オフセット位置定義
            const MyFloat offset[] = {0, 0, 0};
            const MyFloat speedX[] = {2, 0, -2};
            for ( MyS32 cnt = 0; cnt < 3; cnt++)
            {
                auto turret_tmp = turretArray->AddTurret<CTurretSimple>
                        (
                                "PlayerBullet",
                                offset[cnt],
                                0.0f, speedX[cnt],
                                m_SpeedY, m_Interval,
                                m_BulletImage
                        );
            }
            return turretArray;
        }
    };
}

#endif //TURRETCREATORTYPETHREEWAY_H
