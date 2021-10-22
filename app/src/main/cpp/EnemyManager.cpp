/******************************************************************************/
/*! @file       EnemyManager.cpp
    @brief      敵管理クラス実装ファイル
*******************************************************************************/

#include "EnemyManager.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CEnemyManager::CEnemyManager()
    : m_CurrentAppear(0)
    , m_EnemyList()
    , m_Placement()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CEnemyManager::~CEnemyManager()
{
    Release();
}

/******************************************************************************/
/*! 読み込み
    @param[in]      epc    敵出現情報生成機
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyManager::Load(EnemyPlacementCreatorPtr epc)
{
    epc->Create(m_Placement);
    return k_Success;
}

/******************************************************************************/
/*! 初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyManager::Initialize()
{
    m_CurrentAppear = 0;
    m_EnemyList.clear();
    return k_Success;
}

/******************************************************************************/
/*! 更新
    @param[in]      scroll    スクロール値
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyManager::Update(MyFloat scroll)
{
    // 敵の出現判定
    while (m_CurrentAppear < m_Placement.GetAppearCount() &&
    scroll >= m_Placement.GetAppear(m_CurrentAppear).scroll)
    {
        auto& enemyAppear = m_Placement.GetAppear(m_CurrentAppear++);
        auto enemy_tmp = std::make_shared<CEnemy>();
        enemy_tmp->Initialize(
                enemyAppear.posX, enemyAppear.posY,
                m_Placement.GetImage(enemyAppear.type),
                m_Placement.GetTurretPattern(enemyAppear.type),
                m_Placement.GetMovePattern(enemyAppear.type));
        m_EnemyList.push_back(enemy_tmp);
    }
    // 敵更新
    for (auto& enemy : m_EnemyList)
    {
        enemy->Update();
    }
    // 終了した敵の消去
    m_EnemyList.erase(
            std::remove_if(m_EnemyList.begin(), m_EnemyList.end(),
                    [](RKMy(EnemyPtr) enemy) {return !enemy->IsShow(); }),
            m_EnemyList.end()
            );
    return k_Success;
}

/******************************************************************************/
/*! 描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyManager::Draw()
{
    for (auto& enemy : m_EnemyList)
    {
        enemy->Draw();
    }
    return k_Success;
}

/******************************************************************************/
/*! 解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEnemyManager::Release()
{
    m_EnemyList.clear();
    m_Placement.Release();
    return k_Success;
}