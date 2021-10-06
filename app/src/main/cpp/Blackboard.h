//
// Created by akasu on 2021/10/04.
//

#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include "ParameterMap.h"
#include <tuple>

namespace Shooting2D
{
    template < typename... Types >
    class CBlackboard
    {
    private:
        std::tuple<ParameterMapPtr<Types>...> m_Elements;

        template < MyU32 Index >
        using elementType = typename std::tuple_element<Index, decltype(m_Elements)>::type;

        template < typename T, MyU32 Index >
        using IsElement = std::is_same<elementType<Index>, T>;

        template < typename T, MyU32 Index = 0 >
    struct FindElement : public std::conditional_t
            <
                IsElement<T, Index>::value,
                std::integral_constant< decltype(Index), Index>,
                FindElement<T, Index + 1>
            >
        {
        };

    public:

        CBlackboard()
            : m_Elements()
        {
        }

        template < typename T >
        ParameterMapPtr<T>& Get()
        {
            constexpr MyU32 index = FindElement<ParameterMapPtr<T>>::value;
            auto& result = std::get<index>(m_Elements);
            if (result == nullptr)
            {
                result = std::make_shared<CParameterMap<T>>();
            }
            return result;
        }

        template < typename T >
        RKMy(ParameterMapPtr<T>) Get() const
        {
            return const_cast<CBlackboard*>(this)->Get<T>();
        }

        template < typename T >
        T& Get(RKMy(ParameterMapKeyType) key)
        {
            auto& result = Get<T>();
            return result->Get(key);
        }

        template < typename T >
        RKMy(T) Get(RKMy(ParameterMapKeyType) key) const
        {
            return const_cast<CBlackboard*>(this)->Get<T>(key);
        }

        template < typename T >
        size_t GetSize() const
        {
            return Get<T>()->GetSize();
        }
    };
    template < typename... Types >
    using BlackboardPtr = std::shared_ptr<CBlackboard<Types...>>;
}

#endif //BLACKBOARD_H
