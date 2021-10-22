/******************************************************************************/
/*! @file       TurretFixedPointer.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETFIXEDPOINTER_H
#define TURRETFIXEDPOINTER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretFixedPointer
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretFixedPointer : public CTurretDecorator
    {
    protected:

        /*! 弾の発射位置 */
        MyFloat m_PosX;
        MyFloat m_PosY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      px    発射位置X
            @param[in]      py    発射位置Y
        *******************************************************************************/
        explicit CTurretFixedPointer(MyFloat px, MyFloat py)
            : CTurretDecorator()
            , m_PosX(px)
            , m_PosY(py)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretFixedPointer() override
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
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETFIXEDPOINTER_H
