//
// Created by akasu on 2021/10/09.
//

#ifndef EFFECT_H
#define EFFECT_H

#include "GameObject.h"
#include "Animator.h"

namespace Shooting2D
{
    class CEffect : public CGameObject
    {
    private:
        AnimatorPtr m_Animator;

    public:
        explicit CEffect(MyFloat px, MyFloat py, AnimationListPtr anims);

        virtual ~CEffect() override;

        virtual MyS32 Update() override;

        virtual MyS32 Draw() override;
    };

    using EffectPtr = std::shared_ptr<CEffect>;
    using EffectList = std::list<EffectPtr>;
}


#endif //EFFECT_H
