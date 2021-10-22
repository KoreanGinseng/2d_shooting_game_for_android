/******************************************************************************/
/*! @file       EffectEmitter.h
    @brief      エフェクト放出機クラス定義ファイル
*******************************************************************************/

#ifndef EFFECTEMITTER_H
#define EFFECTEMITTER_H

#include "Effect.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class IEffectEmitter
        @brief  エフェクト放出機クラス
    *******************************************************************************/
    class IEffectEmitter
    {
    protected:
        /******************************************************************************/
        /*! 生成
            @param[in]      bimg       ベース画像ID
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Create(MyInt bimg) = 0;

    public:
        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~IEffectEmitter() = default;

        /******************************************************************************/
        /*! エフェクトの発生
            @param[in]      px       発生座標X
            @param[in]      py       発生座標Y
            @return         エフェクトポインタ
        *******************************************************************************/
        virtual EffectPtr Emit(MyFloat px, MyFloat py) = 0;
    };

    /*! ポインタ置き換え */
    using EffectEmitterPtr = std::shared_ptr<IEffectEmitter>;
    using EffectEmitterArray = std::vector<EffectEmitterPtr>;
}

#endif //EFFECTEMITTER_H
