//
// Created by akasu on 2021/10/20.
//

#ifndef TURRETCREATORTYPE4_H
#define TURRETCREATORTYPE4_H

#include "TurretCreatorType1.h"
#include "TurretPlayerLockon.h"

namespace Shooting2D
{
    class CTurretCreatorType4 : public CTurretCreatorType1
    {
    public:
        using CTurretCreatorType1::CTurretCreatorType1;

        virtual ~CTurretCreatorType4() = default;

        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretSimple>(
                    m_ListName, m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY, m_Interval, m_BulletImage
                    )
                    ->Decorate<CTurretPlayerLockon>(m_SpeedY);
        }
    };
}

#endif //TURRETCREATORTYPE4_H
