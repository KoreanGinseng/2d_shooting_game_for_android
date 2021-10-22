/******************************************************************************/
/*! @file       MissionPlayerDead.h
    @brief      ミッションフラグクラス定義ファイル
*******************************************************************************/

#ifndef MISSIONPLAYERDEAD_H
#define MISSIONPLAYERDEAD_H

#include "MissionFlag.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMissionPlayerDead
        @brief  ミッションフラグクラス
    *******************************************************************************/
    class CMissionPlayerDead : public IMissionFlag
    {
    public:

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMissionPlayerDead() override = default;

        /******************************************************************************/
        /*! 有効フラグの取得
            @return         有効フラグ
        *******************************************************************************/
        virtual MyBool IsValid() const noexcept override
        {
            CPlayer& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
            return !player.IsShow();
        }
    };
}

#endif //MISSIONPLAYERDEAD_H
