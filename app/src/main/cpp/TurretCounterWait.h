/******************************************************************************/
/*! @file       TurretCounterWait.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCOUNTERWAIT_H
#define TURRETCOUNTERWAIT_H

#include "TurretCounter.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCounterWait
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretCounterWait : public CTurretCounter
    {
    protected:

        /*! 発射カウンタ */
        MyS32 m_ResetCount;

        /*! 発射間隔 */
        MyS32 m_Interval;

        /*! 発射ウェイト */
        MyS32 m_Wait;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      count    カウンタ
            @param[in]      wait     間隔
        *******************************************************************************/
        explicit CTurretCounterWait(MyS32 count, MyS32 wait)
            : CTurretCounter()
            , m_ResetCount(count)
            , m_Interval(wait)
            , m_Wait(0)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCounterWait() override = default;

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Update(MyFloat px, MyFloat py) override
        {
            // ウェイトの減少
            m_Wait--;
            // ウェイトがある場合待機
            if (m_Wait > 0)
            {
                return k_failure;
            }
            MyBool result = CTurretCounter::Update(px, py);
            if (m_FireCount >= m_ResetCount)
            {
                m_FireCount = 0;
                m_Wait = m_Interval;
            }
            return result;
        }

        /******************************************************************************/
        /*! このフレームでの発射判定
            @return         発射フラグ
        *******************************************************************************/
        virtual MyBool IsFire() const noexcept override
        {
            return (m_Wait <= 1 && m_Wait >= 0);
        }
    };
}

#endif //TURRETCOUNTERWAIT_H
