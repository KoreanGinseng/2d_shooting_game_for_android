//
// Created by akasu on 2021/10/13.
//

#ifndef MISSION_H
#define MISSION_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class IMission
    {
    public:
        virtual ~IMission() = default;

        virtual MyBool IsSuccessed() const noexcept = 0;

        virtual MyBool IsFailed() const noexcept = 0;
    };
    using MissionPtr = std::shared_ptr<IMission>;

    template < class Successed, class Failed >
    class CMission : public IMission
    {
    private:
        std::shared_ptr< Successed > m_SuccessedFlag;
        std::shared_ptr< Failed >    m_FailedFlag;
    public:
        CMission()
            : m_SuccessedFlag(std::make_shared<Successed>())
            , m_FailedFlag(std::make_shared<Failed>())
        {
        }

        virtual MyBool IsSuccessed() const noexcept override
        {
            return m_SuccessedFlag->IsValid();
        }

        virtual MyBool IsFailed() const noexcept override
        {
            return m_FailedFlag->IsValid();
        }
    };
}

#endif //MISSION_H
