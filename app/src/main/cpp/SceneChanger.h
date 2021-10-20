//
// Created by akasu on 2021/10/12.
//

#ifndef SCENECHANGER_H
#define SCENECHANGER_H

#include "Scene.h"
#include "SceneChangeEffect.h"

namespace Shooting2D
{
    class ISceneChanger
    {
    public:
        virtual ~ISceneChanger() = default;

        virtual MyBool Change(RKMy(SceneKey) key) = 0;

        virtual MyBool Change(RKMy(SceneKey) key, SceneChangeEffectPtr effect) = 0;
    };
    using SceneChangerPtr = std::shared_ptr<ISceneChanger>;
}

#endif //SCENECHANGER_H
