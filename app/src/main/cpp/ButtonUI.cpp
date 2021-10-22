/******************************************************************************/
/*! @file       ButtonUI.cpp
    @brief      ボタンUIクラス実装ファイル
*******************************************************************************/

#include "ButtonUI.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      btn    ボタン
*******************************************************************************/
CButtonUI::CButtonUI(ButtonPtr btn)
    : m_Button(btn)
    , m_BaseImage(-1)
    , m_PushImage(-1)
    , m_OnBaseImage(-1)
    , m_OnPushImage(-1)
    , m_bPushFlag(false)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CButtonUI::~CButtonUI()
{
}

/******************************************************************************/
/*! 読み込み
    @param[in]      baseImg      ベース画像ID
    @param[in]      pushImg      押されている画像ID
    @param[in]      onBaseImg    チェック済みベース画像ID
    @param[in]      onPushImg    チェック済み押されている画像ID
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CButtonUI::Load(MyInt baseImg, MyInt pushImg, MyInt onBaseImg, MyInt onPushImg)
{
    m_BaseImage = baseImg;
    m_PushImage = pushImg;
    m_OnBaseImage = onBaseImg;
    m_OnPushImage = onPushImg;
    return k_Success;
}

/******************************************************************************/
/*! 描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CButtonUI::Draw()
{
    // ボタンがなければ描画しない
    if (m_Button == nullptr) { return k_Success; }
    // 表示する画像を選ぶ
    MyInt drawImg = -1;
    if (m_bPushFlag)
    {
        if (m_Button->IsPress()) { drawImg = m_OnPushImage; }
        else { drawImg = m_OnBaseImage; }
    }
    else
    {
        if (m_Button->IsPress()) { drawImg = m_PushImage; }
        else { drawImg = m_BaseImage; }
    }

    // 画像があれば描画
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

/******************************************************************************/
/*! 解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CButtonUI::Release()
{
    DxLib::DeleteGraph(m_OnBaseImage);
    DxLib::DeleteGraph(m_OnPushImage);
    DxLib::DeleteGraph(m_BaseImage);
    DxLib::DeleteGraph(m_PushImage);
    return k_Success;
}