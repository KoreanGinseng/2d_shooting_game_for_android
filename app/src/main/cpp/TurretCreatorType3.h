/******************************************************************************/
/*! @file       TurretCreatorType3.h
    @brief      砲台生成機種類3クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPE3_H
#define TURRETCREATORTYPE3_H

#include "TurretCreatorType1.h"
#include "TurretRandomRotater.h"
#include "TurretPlayerLockon.h"
#include "TurretCounterReset.h"
#include "TurretCounterWait.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorType3
        @brief  砲台生成機種類3クラス
    *******************************************************************************/
    class CTurretCreatorType3 : public CTurretCreatorType1
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorType3() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
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
