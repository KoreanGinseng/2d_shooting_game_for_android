/******************************************************************************/
/*! @file       TurretFrameTimer.h
    @brief      弾発射機能装飾クラス
*******************************************************************************/

#ifndef TURRETFRAMETIMER_H
#define TURRETFRAMETIMER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretFrameTimer
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretFrameTimer : public CTurretDecorator
    {
    protected:

        /*! カウンタ */
        MyS32 m_Timer;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      t    タイマー
        *******************************************************************************/
        explicit CTurretFrameTimer(MyS32 t)
            : m_Timer(t)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretFrameTimer() override = default;

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            m_Timer--;
            if (m_Timer > 0)
            {
                return k_failure;
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETFRAMETIMER_H
