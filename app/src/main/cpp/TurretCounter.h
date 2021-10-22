/******************************************************************************/
/*! @file       TurretCounter.h
    @brief      弾発射機能装飾処理クラス定義ファイル
*******************************************************************************/

#ifndef TURRETCOUNTER_H
#define TURRETCOUNTER_H

#include "TurretDecorator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretCounter
        @brief  弾発射機能装飾処理クラス定義ファイル
    *******************************************************************************/
    class CTurretCounter : public CTurretDecorator
    {
    protected:

        /*! 発射カウンタ */
        MyS32 m_FireCount;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CTurretCounter()
            : CTurretDecorator()
            , m_FireCount(0)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretCounter() override
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
                m_FireCount++;
            }
            return result;
        }
    };
}

#endif //TURRETCOUNTER_H
