/******************************************************************************/
/*! @file       TurretCreatorType4.h
    @brief      砲台生成機種類4クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPE4_H
#define TURRETCREATORTYPE4_H

#include "TurretCreatorType1.h"
#include "TurretPlayerLockon.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorType4
        @brief  砲台生成機種類4クラス
    *******************************************************************************/
    class CTurretCreatorType4 : public CTurretCreatorType1
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretCreatorType1::CTurretCreatorType1;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorType4() = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
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
