//
// Created by akasu on 2021/10/09.
//

#ifndef SCORE_H
#define SCORE_H

#include "GameDefine.h"

namespace Shooting2D
{
    class CScore
    {
    private:
        MyS32 m_Score;

    public:
        CScore()
            : m_Score(0)
        {
        }

        ~CScore() = default;

        MyVoid Reset() noexcept
        {
            m_Score = 0;
        }

        MyVoid Add(MyS32 value) noexcept
        {
            m_Score += value;
        }

        const MyS32 Get() const noexcept
        {
            return m_Score;
        }
    };
    using ScorePtr = std::shared_ptr<CScore>;
}

#endif //SCORE_H
