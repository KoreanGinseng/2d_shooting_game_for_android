/******************************************************************************/
/*! @file       TurretRandomRotater.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETRANDOMROTATER_H
#define TURRETRANDOMROTATER_H

#include "TurretDecorator.h"
#include "RandomUtility.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretRandomRotater
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretRandomRotater : public CTurretDecorator
    {
    protected:

        /*! 弾の回転量 */
        MyFloat m_Speed;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      speed    スピード
        *******************************************************************************/
        explicit CTurretRandomRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretRandomRotater() override
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
            if (IsFire())
            {
                MyFloat p = (CRandomUtility::RandomFloat() * 2.0f) - 1;
                MyFloat sina = std::sinf(ToRadian(m_Speed * p));
                MyFloat cosa = std::cosf(ToRadian(m_Speed * p));
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * cosa + vy * -sina, vx * sina + vy * cosa);
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETRANDOMROTATER_H
