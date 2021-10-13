//
// Created by akasu on 2021/10/13.
//

#ifndef SCENECHANGEEFFECT_H
#define SCENECHANGEEFFECT_H

#include "Scene.h"

namespace Shooting2D
{
    class ISceneChangeEffect
    {
    public:
        virtual ~ISceneChangeEffect() = default;

        virtual MyS32 Update() = 0;

        virtual MyS32 Draw(ScenePtr& prev, MyInt prevImg, ScenePtr& current, MyInt currentImg) = 0;

        virtual MyBool IsEnd() const noexcept = 0;
    };
    using SceneChangeEffectPtr = std::shared_ptr<ISceneChangeEffect>;
}

#endif //SCENECHANGEEFFECT_H
