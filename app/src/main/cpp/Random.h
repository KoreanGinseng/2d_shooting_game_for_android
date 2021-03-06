/******************************************************************************/
/*! @file       Random.h
    @brief      乱数クラス定義ファイル
*******************************************************************************/

#ifndef RANDOM_H
#define RANDOM_H

#include <cassert>
#include <random>
#include <memory>
#include "Common.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! @class IRandom
        @brief  乱数クラス
    *******************************************************************************/
    class IRandom
    {
    public:
        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~IRandom() = default;

        /******************************************************************************/
        /*! 乱数の生成
            @param[in]      low    最低値
            @param[in]      high    最高値
            @return         low ~ highまでのランダムな値
        *******************************************************************************/
        virtual MyS32 Random(MyS32 low, MyS32 high) = 0;

        /******************************************************************************/
        /*! シードのリセット
        *******************************************************************************/
        virtual MyVoid ResetSeed() = 0;
    };

    /*! ポインタ置き換え */
    using RandomPtr = std::shared_ptr<IRandom>;
    using RandomUniquePtr = std::unique_ptr<IRandom>;
}

#endif //RANDOM_H
