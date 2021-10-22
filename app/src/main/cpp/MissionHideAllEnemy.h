/******************************************************************************/
/*! @file       MissionHideAllEnemy.h
    @brief      ミッションフラグクラス定義ファイル
*******************************************************************************/

#ifndef MISSIONHIDEALLENEMY_H
#define MISSIONHIDEALLENEMY_H

#include "MissionFlag.h"
#include "EnemyManager.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMissionHideAllEnemy
        @brief  ミッションフラグクラス
    *******************************************************************************/
    class CMissionHideAllEnemy : public IMissionFlag
    {
    public:

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        ~CMissionHideAllEnemy() = default;

        /******************************************************************************/
        /*! 有効フラグの取得
            @return         有効フラグ
        *******************************************************************************/
        virtual MyBool IsValid() const noexcept override
        {
            auto& enemy = CSingletonBlackboard<CEnemyManager>::GetInstance().Get<CEnemyManager>("EnemyManager");
            return enemy.IsHideAllEnemy();
        }
    };
}

#endif //MISSIONHIDEALLENEMY_H
