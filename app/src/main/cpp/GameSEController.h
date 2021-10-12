//
// Created by akasu on 2021/10/08.
//

#ifndef GAMESECONTROLLER_H
#define GAMESECONTROLLER_H

#include "SEController.h"
#include "ServiceLocator.h"
#include "GameDefine.h"
#include <DxLib.h>

namespace Shooting2D
{
    class CGameSEController : public ISEController< SEType >
    {
    private:
        MyInt   m_Sounds[k_SECount];

        MyFloat m_Volume;

    public:
        CGameSEController()
            : m_Sounds()
            , m_Volume(1.0f)
        {
        }

        virtual ~CGameSEController() override
        {
            for (auto& s : m_Sounds)
            {
                DxLib::DeleteSoundMem(s);
            }
        }

        virtual MyS32 Load(RKMy(SEType) id, LPKMyS8 fileName) override
        {
            m_Sounds[(MyS32)id] = DxLib::LoadSoundMem(fileName);
            return ((m_Sounds[(MyS32)id] != -1) ? k_Success : k_failure);
        }

        virtual MyS32 Play(RKMy(SEType) id) override
        {
            MyInt handle = m_Sounds[(MyS32)id];
            DxLib::SetVolumeSoundMem(handle, (MyS32)(m_Volume * 10000));
            return ((DxLib::PlaySoundMem(handle, DX_PLAYTYPE_BACK) != -1) ? k_Success : k_failure);
        }

        virtual MyVoid SetVolume(MyFloat vol) override
        {
            m_Volume = vol;
        }
    };
}

#endif //GAMESECONTROLLER_H
