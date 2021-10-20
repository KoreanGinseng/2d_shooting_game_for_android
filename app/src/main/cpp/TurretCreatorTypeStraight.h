//
// Created by akasu on 2021/10/13.
//

#ifndef TURRETCREATORTYPESTRAIGHT_H
#define TURRETCREATORTYPESTRAIGHT_H

#include "TurretCreatorType1.h"

namespace Shooting2D
{
    class CTurretCreatorTypeStraight : public CTurretCreatorType1
    {
    protected:

    public:
        using CTurretCreatorType1::CTurretCreatorType1;

        virtual ~CTurretCreatorTypeStraight() override = default;

        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretSimple>(
                    m_ListName, m_OffsetX, m_OffsetY,
                    m_SpeedX, m_SpeedY, m_Interval, m_BulletImage
                    );
        }
    };
}

#endif //TURRETCREATORTYPESTRAIGHT_H
