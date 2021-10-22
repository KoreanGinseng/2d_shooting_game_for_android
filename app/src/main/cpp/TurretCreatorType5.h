/******************************************************************************/
/*! @file       TurretCreatorType5.h
    @brief      砲台生成機種類5クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCREATORTYPE5_H
#define TURRETCREATORTYPE5_H

#include "TurretCreatorType4.h"
#include "TurretFrameTimer.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCreatorType5
        @brief  砲台生成機種類5クラス
    *******************************************************************************/
    class CTurretCreatorType5 : public CTurretCreatorType4
    {
    protected:

        /*! タイマー */
        MyS32 m_Timer;

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
            @param[in]      t       タイマー
        *******************************************************************************/
        explicit CTurretCreatorType5(
                RKMyString list, MyFloat offx, MyFloat offy,
                MyFloat sx, MyFloat sy, MyS32 wait, MyInt img, MyS32 t
                )
            : CTurretCreatorType4(list, offx, offy, sx, sy, wait, img)
            , m_Timer(t)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCreatorType5() override = default;

        /******************************************************************************/
        /*! 砲台の生成
            @return         生成された砲台ポインタ
        *******************************************************************************/
        virtual TurretPtr Create() override
        {
            return CTurretCreatorType4::Create()->Decorate<CTurretFrameTimer>(m_Timer);
        }
    };
}

#endif //TURRETCREATORTYPE5_H
