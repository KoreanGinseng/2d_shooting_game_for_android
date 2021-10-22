/******************************************************************************/
/*! @file       Animation.cpp
    @brief      アニメーションクラス実装ファイル
*******************************************************************************/

#include "Animation.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CAnimation::CAnimation()
    : m_FrameArray()
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CAnimation::~CAnimation()
{
    MyS32 result = Release();
    if (result != k_Success)
    {
        MyLOGD("%ld : animation release failure\n", result);
    }
}

/******************************************************************************/
/*! アニメーションフレームの追加
    @param[in]      ox     オフセット位置X
    @param[in]      oy     オフセット位置Y
    @param[in]      w      横幅
    @param[in]      h      高さ
    @param[in]      f      フレーム番号
    @param[in]      img    画像ID
    @return         this
*******************************************************************************/
CAnimation& CAnimation::AddFrame(MyS32 ox, MyS32 oy, MyS32 w, MyS32 h, MyS32 f, MyInt img)
{
    Frame frame;
    frame.offsetX = ox;
    frame.offsetY = oy;
    frame.width   = w;
    frame.height  = h;
    frame.frame   = f;
    frame.image   = DxLib::DerivationGraph(ox, oy, w, h, img);
    m_FrameArray.push_back(frame);
    return *this;
}

/******************************************************************************/
/*! アニメーションの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CAnimation::Release()
{
    for (auto& frame : m_FrameArray)
    {
        if (DxLib::DeleteGraph(frame.image) != 0)
        {
            return k_failure;
        }
    }
    m_FrameArray.clear();
    return k_Success;
}