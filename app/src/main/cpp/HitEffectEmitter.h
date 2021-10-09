//
// Created by akasu on 2021/10/09.
//

#ifndef HITEFFECTEMITTER_H
#define HITEFFECTEMITTER_H

#include "EffectEmitter.h"

namespace Shooting2D
{
    class CHitEffectEmitter : public IEffectEmitter
    {
    protected:
        AnimationListPtr  m_AnimationList;

        virtual MyS32 Create(MyInt bimg) override
        {
            // アニメーション生成
            m_AnimationList = std::make_shared<CAnimationList>(1);
            auto def = m_AnimationList->GetAnimation(0);
            def->AddFrame(  0, 0, 120, 120, 2, bimg);
            def->AddFrame(120, 0, 120, 120, 2, bimg);
            def->AddFrame(240, 0, 120, 120, 2, bimg);
            def->AddFrame(360, 0, 120, 120, 2, bimg);
            def->AddFrame(480, 0, 120, 120, 2, bimg);
            def->AddFrame(600, 0, 120, 120, 2, bimg);
            def->AddFrame(720, 0, 120, 120, 2, bimg);
            def->AddFrame(840, 0, 120, 120, 2, bimg);
            def->AddFrame(960, 0, 120, 120, 2, bimg);
            return k_Success;
        }

    public:
        CHitEffectEmitter()
            : m_AnimationList()
        {
        }

        virtual ~CHitEffectEmitter() override = default;

        static EffectEmitterPtr CreateEmitter(MyInt bimg)
        {
            auto result = std::make_shared<CHitEffectEmitter>();
            result->Create(bimg);
            return result;
        }

        virtual EffectPtr Emit(MyFloat px, MyFloat py) override
        {
            auto& list = CSingletonBlackboard<EffectList>::GetInstance().Get<EffectList>("Effect");
            auto efc = std::make_shared<CEffect>(px, py, m_AnimationList);
            list.push_back(efc);
            return efc;
        }
    };
}

#endif //HITEFFECTEMITTER_H
