/******************************************************************************/
/*! @file       TurretCreatorTypeNearEnemyHoming.h
    @brief      砲台生成機クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPENEARENEMYHOMING_H
#define TURRETCREATORTYPENEARENEMYHOMING_H

#include "TurretCreatorType1.h"
#include "TurretHoming.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorTypeNearEnemyHoming
        @brief  砲台生成機クラス
    *******************************************************************************/
    class CTurretCreatorTypeNearEnemyHoming : public CTurretCreatorType1
    {
    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorTypeNearEnemyHoming() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretHoming>(
                    m_ListName, m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY, m_Interval, m_BulletImage
                    );
        }
    };
}

#endif //TURRETCREATORTYPENEARENEMYHOMING_H
