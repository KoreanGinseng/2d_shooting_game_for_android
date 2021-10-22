/******************************************************************************/
/*! @file       SingletonBlackboard.h
    @brief      シングルトンブラックボードクラス定義ファイル
*******************************************************************************/

#ifndef SINGLETONBLACKBOARD_H
#define SINGLETONBLACKBOARD_H

#include "Blackboard.h"
#include "Singleton.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CSingletonBlackboard
        @brief  ブラックボードクラスをシングルトンとしてアクセスする用クラス
    *******************************************************************************/
    template < typename... Types >
    class CSingletonBlackboard : public CSingleton<CBlackboard<Types...>>
    {
        friend class CSingleton<CBlackboard<Types...>>;
    };
}

#endif //SINGLETONBLACKBOARD_H
