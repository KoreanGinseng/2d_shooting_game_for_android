//
// Created by akasu on 2021/10/09.
//

#ifndef EXPLOSIONEFFECTEMITTER_H
#define EXPLOSIONEFFECTEMITTER_H

#include "EffectEmitter.h"
#include "GameSEController.h"

namespace Shooting2D
{
    class CExplosionEffectEmitter : public IEffectEmitter
    {
    protected:
        AnimationListPtr m_AnimationList;

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
        CExplosionEffectEmitter()
            : m_AnimationList()
        {
        }

        virtual ~CExplosionEffectEmitter() override = default;

        static EffectEmitterPtr CreateEmitter(MyInt bimg)
        {
            auto result = std::make_shared<CExplosionEffectEmitter>();
            result->Create(bimg);
            return result;
        }

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
