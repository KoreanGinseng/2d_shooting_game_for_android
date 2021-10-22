/******************************************************************************/
/*! @file       GameSEController.h
    @brief      SE管理用クラス定義ファイル
*******************************************************************************/

#ifndef GAMESECONTROLLER_H
#define GAMESECONTROLLER_H

#include "SEController.h"
#include "ServiceLocator.h"
#include "GameDefine.h"
#include <DxLib.h>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CGameSEController
        @brief  SE管理用クラス
    *******************************************************************************/
    class CGameSEController : public ISEController< SEType >
    {
    private:

        /*! サウンドハンドル */
        MyInt   m_Sounds[k_SECount];

        /*! 音量 */
        MyFloat m_Volume;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CGameSEController()
            : m_Sounds()
            , m_Volume(1.0f)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CGameSEController() override
        {
            for (auto& s : m_Sounds)
            {
                DxLib::DeleteSoundMem(s);
            }
        }

        /******************************************************************************/
        /*! 読み込み
            @param[in]      id          登録キー
            @param[in]      fileName    ファイルパス
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Load(RKMy(SEType) id, LPKMyS8 fileName) override
        {
            m_Sounds[(MyS32)id] = DxLib::LoadSoundMem(fileName);
            return ((m_Sounds[(MyS32)id] != -1) ? k_Success : k_failure);
        }

        /******************************************************************************/
        /*! 再生
            @param[in]      id          登録キー
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Play(RKMy(SEType) id) override
        {
            MyInt handle = m_Sounds[(MyS32)id];
            DxLib::SetVolumeSoundMem(handle, (MyS32)(m_Volume * 10000));
            return ((DxLib::PlaySoundMem(handle, DX_PLAYTYPE_BACK) != -1) ? k_Success : k_failure);
        }

        /******************************************************************************/
        /*! 音量の設定
            @param[in]      vol          設定値
        *******************************************************************************/
        virtual MyVoid SetVolume(MyFloat vol) override
        {
            m_Volume = vol;
        }
    };
}

#endif //GAMESECONTROLLER_H
