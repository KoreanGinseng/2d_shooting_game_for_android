//
// Created by akasu on 2021/10/06.
//

#include "EnemyPlacement.h"
#include <DxLib.h>

using namespace Shooting2D;

CEnemyPlacement::CEnemyPlacement()
    : m_Placement()
    , m_ImageArray()
{
}

CEnemyPlacement::~CEnemyPlacement()
{
    Release();
}

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

MyVoid CEnemyPlacement::AddAppear(MyFloat px, MyFloat py, MyFloat scroll, MyS32 type)
{
    m_Placement.push_back({px, py, scroll, type});
}

MyVoid CEnemyPlacement::Release()
{
    for (auto n : m_ImageArray)
    {
        DxLib::DeleteGraph(n);
    }
    m_ImageArray.clear();
}

const MyInt CEnemyPlacement::GetImage(MyS32 n) const noexcept
{
    return m_ImageArray[n];
}

RKMy(CEnemyPlacement::Appear) CEnemyPlacement::GetAppear(MyS32 n) const noexcept
{
    return m_Placement[n];
}

const size_t CEnemyPlacement::GetAppearCount() const noexcept
{
    return m_Placement.size();
}
