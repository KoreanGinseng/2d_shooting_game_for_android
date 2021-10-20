//
// Created by akasu on 2021/10/13.
//

#ifndef TEST_BULLETHOMING_H
#define TEST_BULLETHOMING_H

#include "Bullet.h"

namespace Shooting2D
{
    class CBulletHoming : public CBullet
    {
    private:

        GameObjectPtr m_Target;

        MyFloat m_MaxSpeed;

    public:

        explicit CBulletHoming(GameObjectPtr target);

        virtual ~CBulletHoming() override;

        virtual MyS32 Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img) override;

        virtual MyS32 Update() override;
    };
}


#endif //TEST_BULLETHOMING_H
