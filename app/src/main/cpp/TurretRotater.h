/******************************************************************************/
/*! @file       TurretRotater.h
    @brief      バラマキ用デコレータクラス定義ファイル
*******************************************************************************/

#ifndef TURRETROTATER_H
#define TURRETROTATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretRotater
        @brief  バラマキ用デコレータクラス
    *******************************************************************************/
    class CTurretRotater : public CTurretDecorator
    {
    protected:

        /*! 弾の回転量 */
        MyFloat m_Speed;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      speed    回転速度
        *******************************************************************************/
        explicit CTurretRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }


        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretRotater() override
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
            // 発射したら回転実行
            if (result == k_Success)
            {
                MyFloat sina = std::sinf(ToRadian(m_Speed));
                MyFloat cosa = std::cosf(ToRadian(m_Speed));
                MyFloat vx = GetSpeedX();
                MyFloat vy = GetSpeedY();
                SetSpeed(vx * cosa + vy * -sina, vx * sina + vy * cosa);
            }
            return result;
        }
    };
}

#endif //TURRETROTATER_H
