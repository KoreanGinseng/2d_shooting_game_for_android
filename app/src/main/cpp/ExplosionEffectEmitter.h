/******************************************************************************/
/*! @file       ExplosionEffectEmitter.h
    @brief      エフェクト放出機クラス定義ファイル
*******************************************************************************/

#ifndef EXPLOSIONEFFECTEMITTER_H
#define EXPLOSIONEFFECTEMITTER_H

#include "EffectEmitter.h"
#include "GameSEController.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CExplosionEffectEmitter
        @brief  エフェクト放出機クラス
    *******************************************************************************/
    class CExplosionEffectEmitter : public IEffectEmitter
    {
    protected:

        /*! アニメーションリスト */
        AnimationListPtr m_AnimationList;

        /******************************************************************************/
        /*! 生成
            @param[in]      bimg       ベース画像ID
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Create(MyInt bimg) override
        {
            m_AnimationList = std::make_shared<CAnimationList>(1);
            auto def = m_AnimationList->GetAnimation(0);
            def->AddFrame(  0, 0, 120, 120, 3, bimg);
            def->AddFrame(120, 0, 120, 120, 3, bimg);
            def->AddFrame(240, 0, 120, 120, 3, bimg);
            def->AddFrame(360, 0, 120, 120, 3, bimg);
            def->AddFrame(480, 0, 120, 120, 3, bimg);
            return k_Success;
        }

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CExplosionEffectEmitter()
            : m_AnimationList()
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CExplosionEffectEmitter() override = default;

        /******************************************************************************/
        /*! エフェクト放出機の生成
            @param[in]      bimg       ベース画像ID
            @return         エミッターポインタ
        *******************************************************************************/
        static EffectEmitterPtr CreateEmitter(MyInt bimg)
        {
            auto result = std::make_shared<CExplosionEffectEmitter>();
            result->Create(bimg);
            return result;
        }

        /******************************************************************************/
        /*! エフェクトの発生
            @param[in]      px       発生座標X
            @param[in]      py       発生座標Y
            @return         エフェクトポインタ
        *******************************************************************************/
        virtual EffectPtr Emit(MyFloat px, MyFloat py) override
        {
            SEService::GetService()->Play(SEType::Explosion);
            auto& list = CSingletonBlackboard<EffectList>::GetInstance().Get<EffectList>("Effect");
            auto efc = std::make_shared<CEffect>(px, py, m_AnimationList);
            list.push_back(efc);
            return efc;
        }
    };
}

#endif //EXPLOSIONEFFECTEMITTER_H
