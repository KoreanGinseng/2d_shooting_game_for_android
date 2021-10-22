/******************************************************************************/
/*! @file       TurretRandomPointer.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETRANDOMPOINTER_H
#define TURRETRANDOMPOINTER_H

#include "TurretDecorator.h"
#include "RandomUtility.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretRandomPointer
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretRandomPointer : public CTurretDecorator
    {
    protected:
        /*! 弾の発射位置 */
        MyFloat m_AreaLeft;
        MyFloat m_AreaTop;
        MyFloat m_AreaRight;
        MyFloat m_AreaBottom;
        MyFloat m_PosX;
        MyFloat m_PosY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      l    左
            @param[in]      t    上
            @param[in]      r    右
            @param[in]      b    下
        *******************************************************************************/
        explicit CTurretRandomPointer(MyFloat l, MyFloat t, MyFloat r, MyFloat b)
            : m_AreaLeft(l)
            , m_AreaTop(t)
            , m_AreaRight(r)
            , m_AreaBottom(b)
            , m_PosX(0.0f)
            , m_PosY(0.0f)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretRandomPointer() override
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
                MyFloat randX = CRandomUtility::RandomFloat();
                MyFloat randY = CRandomUtility::RandomFloat();
                m_PosX = m_AreaLeft + (m_AreaRight - m_AreaLeft) * randX;
                m_PosY = m_AreaTop + (m_AreaBottom - m_AreaTop) * randY;
            }
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETRANDOMPOINTER_H
