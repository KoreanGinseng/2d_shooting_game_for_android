/******************************************************************************/
/*! @file       TurretCounterReset.h
    @brief      弾発射機能装飾処理クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCOUNTERRESET_H
#define TURRETCOUNTERRESET_H

#include "TurretCounter.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCounterReset
        @brief  弾発射機能装飾処理クラス定義ファイル
    *******************************************************************************/
    class CTurretCounterReset : public CTurretCounter
    {
    protected:

        /*! 発射カウンタ */
        MyS32 m_ResetCount;

        /*! オフセット位置 */
        MyFloat m_OffsetX;
        MyFloat m_OffsetY;

        /*! スピード */
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      count    カウンタ
        *******************************************************************************/
        CTurretCounterReset(MyS32 count)
            : CTurretCounter()
            , m_ResetCount(count)
            , m_OffsetX(0.0f)
            , m_OffsetY(0.0f)
            , m_SpeedX(0.0f)
            , m_SpeedY(0.0f)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCounterReset() override
        {
        }

        /******************************************************************************/
        /*! 初期化
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Initialize() override
        {
            m_FireCount = 0;
            m_Turret->SetOffset(m_OffsetX, m_OffsetY);
            m_Turret->SetSpeed(m_SpeedX, m_SpeedY);
            return m_Turret->Initialize();
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretCounter::Update(px, py);
            if (m_FireCount >= m_ResetCount)
            {
                m_FireCount = 0;
                m_Turret->SetOffset(m_OffsetX, m_OffsetY);
                m_Turret->SetSpeed(m_SpeedX, m_SpeedY);
            }
            return result;
        }

        /******************************************************************************/
        /*! タレットの設定
            @param[in]      obj    タレット
        *******************************************************************************/
        MyVoid SetTurret(TurretPtr obj) override
        {
            m_Turret = obj;
            m_OffsetX = m_Turret->GetOffsetX();
            m_OffsetY = m_Turret->GetOffsetY();
            m_SpeedX = m_Turret->GetSpeedX();
            m_SpeedY = m_Turret->GetSpeedY();
        }
    };
}

#endif //TURRETCOUNTERRESET_H
