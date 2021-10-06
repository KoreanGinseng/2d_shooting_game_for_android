//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCREATORTYPE3_H
#define TURRETCREATORTYPE3_H

#include "TurretCreatorType1.h"
#include "TurretRandomRotater.h"
#include "TurretPlayerLockon.h"
#include "TurretCounterReset.h"
#include "CTurretCounterWait.h"

namespace Shooting2D
{
    class CTurretCreatorType3 : public CTurretCreatorType1
    {
    public:
        using CTurretCreatorType1::CTurretCreatorType1;

        virtual ~CTurretCreatorType3() override = default;

        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretSimple>(m_ListName,
                    m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY,
                    m_Interval, m_BulletImage)
                    ->Decorate<CTurretRandomRotater>(10.0f)
                    ->Decorate<CTurretPlayerLockon>(m_SpeedY)
                    ->Decorate<CTurretWait>(1)
                    ->Decorate<CTurretCounterReset>(10)
                    ->Decorate<CTurretCounterWait>(10, 30);
        }
    };
}

#endif //TURRETCREATORTYPE3_H
