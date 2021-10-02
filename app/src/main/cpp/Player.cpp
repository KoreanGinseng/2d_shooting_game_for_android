/******************************************************************************/
/*! @file       Player.cpp
    @brief      プレイヤー実装ファイル
*******************************************************************************/
#include "Player.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CPlayer::CPlayer()
    : CGameObject()
    , m_Image(0)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CPlayer::~CPlayer()
{
}

/******************************************************************************/
/*! プレイヤーの読み込み
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Load()
{
    // 画像を読み込む
    m_Image = DxLib::LoadGraph("image/Plane/Plane1Up.png");
    if (m_Image == -1)
    {
        return -1;
    }
    // 画像の幅と高さを取得
    int w,h;
    DxLib::GetGraphSize(m_Image, &w, &h);
    // 幅と高さを設定
    m_Width  = w;
    m_Height = h;
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Initialize()
{
    // 画面下中央から開始
    m_bShow = true;
    m_PosX = static_cast<float>(k_SceneWidth - m_Width) * 0.5f;
    m_PosY = static_cast<float>(k_SceneHeight - m_Height) - m_Height * 0.05f;
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }

    // 移動
    MyS32 touchNum = DxLib::GetTouchInputNum();
    if (touchNum <= 0) { return k_Success; }
    MyInt posX = 0, posY = 0;
    MyS32 result = DxLib::GetTouchInput(touchNum - 1, &posX, &posY, nullptr, nullptr);
    if (result == -1) { return k_Success; }
    m_PosX = posX - m_Width  * 0.5f;
    m_PosY = posY - m_Height * 0.5f;
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }
    MyInt drawPosX = static_cast<MyInt>(k_SceneOffsetX + m_PosX);
    MyInt drawPosY = static_cast<MyInt>(k_SceneOffsetY + m_PosY);
    DxLib::DrawGraphF(drawPosX, drawPosY, m_Image, true);
    return k_Success;
}

/******************************************************************************/
/*! プレイヤーの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CPlayer::Release()
{
    DxLib::DeleteGraph(m_Image);
    return k_Success;
}