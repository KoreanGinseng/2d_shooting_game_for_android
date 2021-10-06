//
// Created by akasu on 2021/10/06.
//

#include "EnemyManager.h"

using namespace Shooting2D;

CEnemyManager::CEnemyManager()
    : m_CurrentAppear(0)
    , m_EnemyList()
    , m_Placement()
{
}

CEnemyManager::~CEnemyManager()
{
    Release();
}

MyS32 CEnemyManager::Load(EnemyPlacementCreatorPtr epc)
{
    epc->Create(m_Placement);
    return k_Success;
}

MyS32 CEnemyManager::Initialize()
{
    m_CurrentAppear = 0;
    m_EnemyList.clear();
    return k_Success;
}

MyS32 CEnemyManager::Update(MyFloat scroll)
{
    // 敵の出現判定
    while (m_CurrentAppear < m_Placement.GetAppearCount() &&
    scroll >= m_Placement.GetAppear(m_CurrentAppear).scroll)
    {
        auto& enemyAppear = m_Placement.GetAppear(m_CurrentAppear++);
        auto enemy_tmp = std::make_shared<CEnemy>();
        enemy_tmp->Initialize(enemyAppear.posX, enemyAppear.posY, m_Placement.GetImage(enemyAppear.type), m_Placement.GetTurretPattern(enemyAppear.type));
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

MyS32 CEnemyManager::Draw()
{
    for (auto& enemy : m_EnemyList)
    {
        enemy->Draw();
    }
    return k_Success;
}

MyS32 CEnemyManager::Release()
{
    m_EnemyList.clear();
    m_Placement.Release();
    return k_Success;
}

EnemyList& CEnemyManager::GetEnemyList()
{
    return m_EnemyList;
}