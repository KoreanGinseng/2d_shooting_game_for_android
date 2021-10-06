//
// Created by akasu on 2021/10/02.
//

#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

namespace Shooting2D
{
    class CBullet : public CGameObject
    {
    private:
        /*! 弾の移動速度 */
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

        MyFloat m_Angle;

        /*! 画像ID */
        MyInt   m_Image;

    public:

        CBullet();

        virtual ~CBullet() override;

        MyS32 Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img);

        virtual MyS32 Update() override;

        virtual MyS32 Draw() override;

    };

    using BulletPtr  = std::shared_ptr<CBullet>;
    using BulletList = std::list<BulletPtr>;
}

#endif //BULLET_H
