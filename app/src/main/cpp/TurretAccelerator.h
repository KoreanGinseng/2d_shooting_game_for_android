/******************************************************************************/
/*! @file       TurretAccelerator.h
    @brief      弾発射機能装飾処理クラス定義ファイル
*******************************************************************************/

#ifndef TURRETACCELERATOR_H
#define TURRETACCELERATOR_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretAccelerator
        @brief  弾発射機能装飾処理クラス
    *******************************************************************************/
    class CTurretAccelerator : public CTurretDecorator
    {
    protected:

        /*! 弾の加速量 */
        MyFloat m_Speed;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      speed    加速量
        *******************************************************************************/
        explicit CTurretAccelerator(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretAccelerator() override
        {
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            // 発射したら加速実行
            if (result == k_Success)
            {
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * m_Speed, vy * m_Speed);
            }
            return result;
        }
    };
}

#endif //TURRETACCELERATOR_H
