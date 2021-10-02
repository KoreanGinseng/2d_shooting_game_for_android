//
// Created by akasu on 2021/10/02.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"

namespace Shooting2D
{
    class CBackGround
    {
    private:
        /*! スクロール値 */
        MyFloat m_Scroll;

        /*! 背景の幅と高さ */
        MyS32   m_Width;
        MyS32   m_Height;

        /*! 利用する画像ID */
        MyS32   m_Image;

    public:

        CBackGround();

        ~CBackGround();

        MyS32 Load();

        MyS32 Initialize();

        MyS32 Update();

        MyS32 Draw();

        MyS32 Release();

        MyFloat GetScroll() const noexcept;

    };

}

#endif //BACKGROUND_H
