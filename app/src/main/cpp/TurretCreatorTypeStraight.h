/******************************************************************************/
/*! @file       TurretCreatorTypeStraight.h
    @brief      砲台生成機クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPESTRAIGHT_H
#define TURRETCREATORTYPESTRAIGHT_H

#include "TurretCreatorType1.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorTypeStraight
        @brief  砲台生成機クラス
    *******************************************************************************/
    class CTurretCreatorTypeStraight : public CTurretCreatorType1
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorTypeStraight() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
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
