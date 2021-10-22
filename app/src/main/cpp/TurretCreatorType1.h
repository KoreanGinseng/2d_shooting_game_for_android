/******************************************************************************/
/*! @file       TurretCreatorType1.h
    @brief      砲台生成機種類１クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPE1_H
#define TURRETCREATORTYPE1_H

#include "TurretCreator.h"
#include "TurretSimple.h"
#include "TurretRotater.h"
#include "TurretContinuous.h"
#include "TurretWait.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorType1
        @brief  砲台生成機種類１クラス
    *******************************************************************************/
    class CTurretCreatorType1 : public ITurretCreator
    {
    protected:

        /*! リスト名 */
        std::string m_ListName;
        /*! オフセット位置X */
        MyFloat m_OffsetX;
        /*! オフセット位置Y */
        MyFloat m_OffsetY;
        /*! スピードX */
        MyFloat m_SpeedX;
        /*! スピードY */
        MyFloat m_SpeedY;
        /*! 発射間隔 */
        MyS32 m_Interval;
        /*! 利用する画像ID */
        MyInt m_BulletImage;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      list    リスト名
            @param[in]      offx    オフセット位置X
            @param[in]      offy    オフセット位置Y
            @param[in]      sx      スピードX
            @param[in]      sy      スピードY
            @param[in]      wait    発射間隔
            @param[in]      img     画像ID
        *******************************************************************************/
        explicit CTurretCreatorType1(
                RKMyString list, MyFloat offx, MyFloat offy,
                MyFloat sx, MyFloat sy, MyS32 wait, MyInt img
                )
            : m_ListName(list)
            , m_OffsetX(offx)
            , m_OffsetY(offy)
            , m_SpeedX(sx)
            , m_SpeedY(sy)
            , m_Interval(wait)
            , m_BulletImage(img)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorType1() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
        virtual TurretPtr Create() override
        {
            return std::make_shared<CTurretSimple>(m_ListName,
                    m_OffsetX, m_OffsetY, m_SpeedX, m_SpeedY,
                    m_Interval, m_BulletImage)
                    ->Decorate<CTurretRotater>(36.0f)
                    ->Decorate<CTurretContinuous>(10)
                    ->Decorate<CTurretWait>(10);
        }
    };
}

#endif //TURRETCREATORTYPE1_H
