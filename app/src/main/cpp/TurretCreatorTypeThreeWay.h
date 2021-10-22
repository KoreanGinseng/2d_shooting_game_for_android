/******************************************************************************/
/*! @file       TurretCreatorTypeThreeWay.h
    @brief      砲台生成機クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPETHREEWAY_H
#define TURRETCREATORTYPETHREEWAY_H

#include "TurretCreatorType1.h"
#include "TurretArray.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorTypeThreeWay
        @brief  砲台生成機クラス
    *******************************************************************************/
    class CTurretCreatorTypeThreeWay : public CTurretCreatorType1
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorTypeThreeWay() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
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
