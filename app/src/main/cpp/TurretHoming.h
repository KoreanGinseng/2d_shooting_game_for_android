/******************************************************************************/
/*! @file       TurretHoming.h
    @brief      標的を追跡する砲台クラスの定義ファイル
*******************************************************************************/

#ifndef TURRETHOMING_H
#define TURRETHOMING_H

#include "TurretSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretHoming
        @brief  標的を追跡する砲台クラス
    *******************************************************************************/
    class CTurretHoming : public CTurretSimple
    {
    public:
        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        using CTurretSimple::CTurretSimple;

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretHoming() override = default;

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) override;
    };
}


#endif //TURRETHOMING_H
