//
// Created by akasu on 2021/10/06.
//

#ifndef ENEMYPLACEMENT_H
#define ENEMYPLACEMENT_H

#include <vector>
#include <memory>
#include "Common.h"
#include "TurretCreator.h"
#include "MoveCreator.h"

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
        std::vector<MyInt>  m_BulletImageArray;
        std::vector<TurretCreatorPtr> m_TurretPatternArray;
        std::vector<MoveCreatorPtr> m_MovePatternArray;

    public:
        CEnemyPlacement();

        ~CEnemyPlacement();

        MyS32 AddImage(LPKMyS8 fileName);

        MyS32 AddBulletImage(LPKMyS8 fileName);

        MyVoid AddAppear(MyFloat px, MyFloat py, MyFloat scroll, MyS32 type);

        MyVoid AddTurretPattern(TurretCreatorPtr ptr);

        MyVoid AddMovePattern(MoveCreatorPtr ptr);

        MyVoid Release();

        const MyInt GetImage(MyS32 n) const noexcept;
        const MyInt GetBulletImage(MyS32 n) const noexcept;
        RKMy(Appear) GetAppear(MyS32 n) const noexcept;
        RKMy(TurretCreatorPtr) GetTurretPattern(MyS32 n) const noexcept;
        RKMy(MoveCreatorPtr) GetMovePattern(MyS32 n) const noexcept;
        const size_t GetAppearCount() const noexcept;
    };
    using EnemyPlacementPtr = std::shared_ptr<CEnemyPlacement>;
}

#endif //ENEMYPLACEMENT_H
