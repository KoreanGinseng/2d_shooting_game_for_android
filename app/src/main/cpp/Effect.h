/******************************************************************************/
/*! @file       Effect.h
    @brief      エフェクトクラス定義ファイル
*******************************************************************************/

#ifndef EFFECT_H
#define EFFECT_H

#include "GameObject.h"
#include "Animator.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CEffect
        @brief  エフェクトクラス
    *******************************************************************************/
    class CEffect : public CGameObject
    {
    private:

        /*! アニメーション情報 */
        AnimatorPtr m_Animator;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      px       再生する座標X
            @param[in]      py       再生する座標Y
            @param[in]      anims    再生するアニメーション
        *******************************************************************************/
        explicit CEffect(MyFloat px, MyFloat py, AnimationListPtr anims);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CEffect() override;

        /******************************************************************************/
        /*! 更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update() override;

        /******************************************************************************/
        /*! 描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Draw() override;
    };

    /*! ポインタ置き換え */
    using EffectPtr = std::shared_ptr<CEffect>;
    using EffectList = std::list<EffectPtr>;
}


#endif //EFFECT_H
