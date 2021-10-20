//
// Created by akasu on 2021/10/13.
//

#ifndef TURRETCREATORTYPENEARENEMYHOMING_H
#define TURRETCREATORTYPENEARENEMYHOMING_H

#include "TurretCreatorType1.h"
#include "TurretHoming.h"

namespace Shooting2D
{
    class CTurretCreatorTypeNearEnemyHoming : public CTurretCreatorType1
    {
    public:

        using CTurretCreatorType1::CTurretCreatorType1;

        virtual ~CTurretCreatorTypeNearEnemyHoming() override = default;

        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretHoming>(
                    m_ListName, m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY, m_Interval, m_BulletImage
                    );
        }
    };
}

#endif //TURRETCREATORTYPENEARENEMYHOMING_H
