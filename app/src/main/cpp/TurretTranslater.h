/******************************************************************************/
/*! @file       TurretTranslater.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETTRANSLATER_H
#define TURRETTRANSLATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretTranslater
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretTranslater : public CTurretDecorator
    {
    protected:

        /*! 弾の移動量 */
        MyFloat m_MoveX;
        MyFloat m_MoveY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      mx    スピードX
            @param[in]      my    スピードY
        *******************************************************************************/
        explicit CTurretTranslater(MyFloat mx, MyFloat my)
            : CTurretDecorator()
            , m_MoveX(mx)
            , m_MoveY(my)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretTranslater() override
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
            // 発射したら移動実行
            if (result == k_Success)
            {
                MyFloat ox = GetOffsetX();
                MyFloat oy = GetOffsetY();
                SetOffset(ox + m_MoveX, oy + m_MoveY);
            }
            return result;
        }
    };
}

#endif //TURRETTRANSLATER_H
