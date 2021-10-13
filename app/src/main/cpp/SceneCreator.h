//
// Created by akasu on 2021/10/12.
//

#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include "Scene.h"

namespace Shooting2D
{
    class ISceneCreator
    {
    public:

        virtual ~ISceneCreator() = default;

        virtual ScenePtr Create() = 0;
    };
    using SceneCreatorPtr = std::unique_ptr<ISceneCreator>;
}

#endif //SCENECREATOR_H
