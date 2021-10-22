/******************************************************************************/
/*! @file       EnemyPlacementCreator.h
    @brief      敵配置情報生成クラス定義ファイル
*******************************************************************************/


#ifndef ENEMYPLACEMENTCREATOR_H
#define ENEMYPLACEMENTCREATOR_H

#include "EnemyPlacement.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class IEnemyPlacementCreator
        @brief  敵配置情報生成クラス
    *******************************************************************************/
    class IEnemyPlacementCreator
    {
    public:
        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~IEnemyPlacementCreator() = default;

        /******************************************************************************/
        /*! 敵配置の生成
            @param[in]      placement    敵配置情報
        *******************************************************************************/
        virtual MyVoid Create(CEnemyPlacement& placement) = 0;
    };

    /*! ポインタ置き換え */
    using EnemyPlacementCreatorPtr = std::shared_ptr<IEnemyPlacementCreator>;
}

#endif //ENEMYPLACEMENTCREATOR_H
