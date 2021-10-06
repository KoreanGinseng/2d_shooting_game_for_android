//
// Created by akasu on 2021/10/06.
//

#ifndef COLLISIONFUNCTION_H
#define COLLISIONFUNCTION_H

#include <cmath>
#include "GameObject.h"

namespace Shooting2D
{
    class CCollisionFunction
    {
    public:
        static MyBool CollisionCircle(MyFloat cx1, MyFloat cy1, MyFloat cr1, MyFloat cx2, MyFloat cy2, MyFloat cr2)
        {
            // 座標の差を求める
            MyFloat sx = cx2 - cx1;
            MyFloat sy = cy2 - cy1;
            // 距離を求める
            MyFloat d = sqrt(sx * sx + sy * sy);
            // 半径の合計より距離が小さいかどうかを結果として返す
            return (d < cr1 + cr2);
        }

        static MyBool CollisionGameObject(CGameObject& obj1, CGameObject& obj2)
        {
            return CollisionCircle(
                    obj1.GetPosX(), obj1.GetPosY(), obj1.GetRadius(),
                    obj2.GetPosX(), obj2.GetPosY(), obj2.GetRadius()
                    );
        }

        template < typename T1, typename T2 >
        static MyVoid Collision(T1& obj1, T2& obj2)
        {
            static_assert("Collision Pair Not Found!!");
        }
    };
}

#endif //COLLISIONFUNCTION_H
