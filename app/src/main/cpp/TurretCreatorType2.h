/******************************************************************************/
/*! @file       TurretCreatorType2.h
    @brief      砲台生成機種類2クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPE2_H
#define TURRETCREATORTYPE2_H

#include "TurretCreatorType1.h"
#include "TurretArray.h"
#include "TurretAccelerator.h"
#include "TurretCounterReset.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorType2
        @brief  砲台生成機種類2クラス
    *******************************************************************************/
    class CTurretCreatorType2 : public CTurretCreatorType1
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorType2() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
        virtual TurretPtr Create() override
        {
            auto turretArray = std::make_shared<CTurretArray>();

            turretArray->AddTurret(
                    std::make_shared<CTurretSimple>
                    (m_ListName, m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY, m_Interval, m_BulletImage)
                    ->Decorate<CTurretRotater>(36.0f)
                    ->Decorate<CTurretContinuous>(10)
                    ->Decorate<CTurretRotater>(-3.0f)
                    ->Decorate<CTurretAccelerator>(1.05f)
                    ->Decorate<CTurretWait>(5)
                    ->Decorate<CTurretCounterReset>(12));

            turretArray->AddTurret(
                    std::make_shared<CTurretSimple>
                    (m_ListName, m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY, m_Interval, m_BulletImage)
                    ->Decorate<CTurretRotater>(36.0f)
                    ->Decorate<CTurretContinuous>(10)
                    ->Decorate<CTurretRotater>(3.0f)
                    ->Decorate<CTurretAccelerator>(1.05f)
                    ->Decorate<CTurretWait>(5)
                    ->Decorate<CTurretCounterReset>(12));

            return turretArray;
        }
    };
}

#endif //TURRETCREATORTYPE2_H
