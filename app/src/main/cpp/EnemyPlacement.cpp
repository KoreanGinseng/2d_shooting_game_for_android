/******************************************************************************/
/*! @file       EnemyPlacement.cpp
    @brief      敵配置情報クラス実装ファイル
*******************************************************************************/

#include "EnemyPlacement.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CEnemyPlacement::CEnemyPlacement()
    : m_Placement()
    , m_ImageArray()
    , m_BulletImageArray()
    , m_TurretPatternArray()
    , m_MovePatternArray()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CEnemyPlacement::~CEnemyPlacement()
{
    Release();
}

/******************************************************************************/
/*! 敵画像の追加
    @param[in]      fileName    画像ファイルパス
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyPlacement::AddImage(LPKMyS8 fileName)
{
    MyInt img = DxLib::LoadGraph(fileName);
    if(img == -1)
    {
        return k_failure;
    }
    m_ImageArray.push_back(img);
    return k_Success;
}

/******************************************************************************/
/*! 弾画像の追加
    @param[in]      fileName    画像ファイルパス
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyPlacement::AddBulletImage(LPKMyS8 fileName)
{
    MyInt img = DxLib::LoadGraph(fileName);
    if(img == -1)
    {
        return k_failure;
    }
    m_BulletImageArray.push_back(img);
    return k_Success;
}

/******************************************************************************/
/*! 出現情報の追加
    @param[in]      px        出現位置X
    @param[in]      py        出現位置Ｙ
    @param[in]      scroll    出現スクロール
    @param[in]      type      種類
*******************************************************************************/
MyVoid CEnemyPlacement::AddAppear(MyFloat px, MyFloat py, MyFloat scroll, MyS32 type)
{
    m_Placement.push_back({px, py, scroll, type});
}

/******************************************************************************/
/*! 砲台生成機の追加
    @param[in]      ptr        生成機
*******************************************************************************/
MyVoid CEnemyPlacement::AddTurretPattern(TurretCreatorPtr ptr)
{
    m_TurretPatternArray.push_back(ptr);
}

/******************************************************************************/
/*! 移動生成機の追加
    @param[in]      ptr        生成機
*******************************************************************************/
MyVoid CEnemyPlacement::AddMovePattern(MoveCreatorPtr ptr)
{
    m_MovePatternArray.push_back(ptr);
}

/******************************************************************************/
/*! 解放
*******************************************************************************/
MyVoid CEnemyPlacement::Release()
{
    for (auto n : m_ImageArray)
    {
        DxLib::DeleteGraph(n);
    }
    for (auto n : m_BulletImageArray)
    {
        DxLib::DeleteGraph(n);
    }
    m_ImageArray.clear();
    m_BulletImageArray.clear();
}
