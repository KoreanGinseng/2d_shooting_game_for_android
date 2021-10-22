/******************************************************************************/
/*! @file       CollisionFunction.h
    @brief      当たり判定関数群定義ファイル
*******************************************************************************/

#ifndef COLLISIONFUNCTION_H
#define COLLISIONFUNCTION_H

#include <cmath>
#include "GameObject.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! @class CCollisionFunction
        @brief  当たり判定関数群
    *******************************************************************************/
    class CCollisionFunction
    {
    public:
        /******************************************************************************/
        /*! 円の当たり判定
            @param[in]      cx1    円１の座標X
            @param[in]      cy1    円１の座標Y
            @param[in]      cr1    円１の半径
            @param[in]      cx2    円２の座標X
            @param[in]      cy2    円２の座標Y
            @param[in]      cr2    円２の半径
            @return         true 当たっている, false 当たっていない
        *******************************************************************************/
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

        /******************************************************************************/
        /*! ゲームオブジェクトの当たり判定
            @param[in]      obj1    オブジェクト１
            @param[in]      obj2    オブジェクト２
            @return         true 当たっている, false 当たっていない
        *******************************************************************************/
        static MyBool CollisionGameObject(CGameObject& obj1, CGameObject& obj2)
        {
            return CollisionCircle(
                    obj1.GetPosX(), obj1.GetPosY(), obj1.GetRadius(),
                    obj2.GetPosX(), obj2.GetPosY(), obj2.GetRadius()
                    );
        }

        /******************************************************************************/
        /*! 当たり判定テンプレート関数
            @param[in]      obj1    オブジェクト１
            @param[in]      obj2    オブジェクト２
            @return         true 当たっている, false 当たっていない
        *******************************************************************************/
        template < typename T1, typename T2 >
        static MyVoid Collision(T1& obj1, T2& obj2)
        {
            assert(false);
        }
    };
}

#endif //COLLISIONFUNCTION_H
