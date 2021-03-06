/******************************************************************************/
/*! @file       TurretWait.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETWAIT_H
#define TURRETWAIT_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretWait
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretWait : public CTurretDecorator
    {
    protected:

        /*! 発射間隔 */
        MyS32 m_Interval;

        /*! 発射ウェイト */
        MyS32 m_Wait;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      count    間隔
        *******************************************************************************/
        explicit CTurretWait(MyS32 count)
            : CTurretDecorator()
            , m_Interval(count)
            , m_Wait(count)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretWait() override
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
            // ウェイトの減少
            m_Wait--;
            if (m_Wait > 0)
            {
                return k_failure;
            }
            // 次の発射までのウェイトを設定
            m_Wait = m_Interval;
            // 発射
            return CTurretDecorator::Update(px, py);
        }

        /******************************************************************************/
        /*! このフレームでの発射判定
            @return         発射フラグ
        *******************************************************************************/
        virtual MyBool IsFire() const noexcept override
        {
            return (m_Wait <= 1 && m_Turret->IsFire());
        }
    };
}

#endif //TURRETWAIT_H
