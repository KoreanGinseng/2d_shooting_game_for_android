/******************************************************************************/
/*! @file       TurretContinuous.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCONTINUOUS_H
#define TURRETCONTINUOUS_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretContinuous
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretContinuous : public CTurretDecorator
    {
    protected:

        /*! 弾の発射数 */
        MyS32 m_Count;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      count    発射数
        *******************************************************************************/
        CTurretContinuous(MyS32 count)
            : CTurretDecorator()
            , m_Count(count)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretContinuous() override
        {
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = k_failure;
            for (MyS32 i = 0; i < m_Count; i++)
            {
                result |= CTurretDecorator::Update(px, py);
            }
            return result;
        }
    };
}

#endif //TURRETCONTINUOUS_H
