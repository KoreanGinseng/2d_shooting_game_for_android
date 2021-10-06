//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMYPLACEMENT_H
#define ENEMYPLACEMENT_H

#include <vector>
#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class CEnemyPlacement
    {
    private:
        struct Appear
        {
            MyFloat posX;
            MyFloat posY;

            MyFloat scroll;

            MyS32 type;
        };

        std::vector<MyInt>  m_ImageArray;
        std::vector<Appear> m_Placement;

    public:
        CEnemyPlacement();

        ~CEnemyPlacement();

        MyS32 AddImage(LPKMyS8 fileName);

        MyVoid AddAppear(MyFloat px, MyFloat py, MyFloat scroll, MyS32 type);

        MyVoid Release();

        const MyInt GetImage(MyS32 n) const noexcept;
        RKMy(Appear) GetAppear(MyS32 n) const noexcept;
        const size_t GetAppearCount() const noexcept;
    };
    using EnemyPlacementPtr = std::shared_ptr<CEnemyPlacement>;
}

#endif //ENEMYPLACEMENT_H
