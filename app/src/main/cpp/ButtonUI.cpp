//
// Created by akasu on 2021/10/13.
//

#include "ButtonUI.h"
#include <DxLib.h>

using namespace Shooting2D;

CButtonUI::CButtonUI(ButtonPtr btn)
    : m_Button(btn)
    , m_BaseImage(-1)
    , m_PushImage(-1)
    , m_OnBaseImage(-1)
    , m_OnPushImage(-1)
    , m_bPushFlag(false)
{
}

CButtonUI::~CButtonUI()
{
}

MyS32 CButtonUI::Load(MyInt baseImg, MyInt pushImg, MyInt onBaseImg, MyInt onPushImg)
{
    m_BaseImage = baseImg;
    m_PushImage = pushImg;
    m_OnBaseImage = onBaseImg;
    m_OnPushImage = onPushImg;
    return k_Success;
}

MyS32 CButtonUI::Draw()
{
    if (m_Button == nullptr) { return k_Success; }
    MyInt drawImg = -1;
    if (m_bPushFlag)
    {
        if (m_Button->IsPress())
        {
            drawImg = m_OnPushImage;
        }
        else
        {
            drawImg = m_OnBaseImage;
        }
    }
    else
    {
        if (m_Button->IsPress())
        {
            drawImg = m_PushImage;
        }
        else
        {
            drawImg = m_BaseImage;
        }
    }

    if (drawImg != -1)
    {
        DxLib::DrawExtendGraph(
                m_Button->GetLeft(),  m_Button->GetTop(),
                m_Button->GetRight(), m_Button->GetBottom(),
                drawImg, TRUE
                );
    }
    return k_Success;
}

MyVoid CButtonUI::SetPushFlag(MyBool b)
{
    m_bPushFlag = b;
}

MyS32 CButtonUI::Release()
{
    DxLib::DeleteGraph(m_OnBaseImage);
    DxLib::DeleteGraph(m_OnPushImage);
    DxLib::DeleteGraph(m_BaseImage);
    DxLib::DeleteGraph(m_PushImage);
    return k_Success;
}