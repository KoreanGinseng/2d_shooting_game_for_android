/******************************************************************************/
/*! @file       TurretOffsetRotater.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETOFFSETROTATER_H
#define TURRETOFFSETROTATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretOffsetRotater
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretOffsetRotater : public CTurretDecorator
    {
    protected:

        /*! 弾の回転量 */
        MyFloat m_Speed;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      speed    スピード
        *******************************************************************************/
        explicit CTurretOffsetRotater(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretOffsetRotater() override
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
            if (result == k_Success)
            {
                MyFloat sina = std::sinf(ToRadian(m_Speed));
                MyFloat cosa = std::cosf(ToRadian(m_Speed));
                MyFloat ox = GetOffsetX();
                MyFloat oy = GetOffsetY();
                SetOffset(ox * cosa + oy * -sina, ox * sina + oy * cosa);
            }
            return result;
        }
    };
}

#endif //TURRETOFFSETROTATER_H
