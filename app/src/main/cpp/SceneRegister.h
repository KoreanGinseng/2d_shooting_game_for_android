//
// Created by akasu on 2021/10/12.
//

#ifndef SCENEREGISTER_H
#define SCENEREGISTER_H

#include "SceneCreator.h"

namespace Shooting2D
{
    class ISceneRegister
    {
    public:
        virtual ~ISceneRegister() = default;

        virtual MyVoid Regist(RKMy(SceneKey) key, SceneCreatorPtr creator) = 0;
    };
    using SceneRegisterPtr = std::shared_ptr<ISceneRegister>;
}

#endif //SCENEREGISTER_H
