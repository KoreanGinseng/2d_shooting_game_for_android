//
// Created by akasu on 2021/10/02.
//

#ifndef PARAMETERMAP_H
#define PARAMETERMAP_H

#include "Common.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <cassert>

namespace Shooting2D
{
    /*! 利用するキーの置き換え */
    using ParameterMapKeyType = std::string;

    template < typename T >
    class CParameterMap
    {
    public:
        using Parameter = T;

    private:
        std::unordered_map< ParameterMapKeyType, Parameter& > m_Parameters;

    public:
        CParameterMap()
            : m_Parameters()
        {
        }

        CParameterMap& Add(RKMy(ParameterMapKeyType) key, Parameter& value)
        {
            m_Parameters.insert(std::pair<ParameterMapKeyType, Parameter&>(key, value));
            return *this;
        }

        CParameterMap& Delete(RKMy(ParameterMapKeyType) key)
        {
            m_Parameters.erase(key);
            return *this;
        }

        Parameter& Get(RKMy(ParameterMapKeyType) key)
        {
            auto it = m_Parameters.find(key);
            assert(it != m_Parameters.end());
            return it->second;
        }

        RKMy(Parameter) Get(RKMy(ParameterMapKeyType) key) const
        {
            auto it = m_Parameters.find(key);
            assert(it != m_Parameters.end());
            return it->second;
        }

        Parameter& operator[] (RKMy(ParameterMapKeyType) key)
        {
            return Get(key);
        }

        RKMy(Parameter) operator[] (RKMy(ParameterMapKeyType) key) const
        {
            return Get(key);
        }

        size_t GetSize() const
        {
            return m_Parameters.size();
        }

        std::unordered_map<ParameterMapKeyType, Parameter>& Parameters()
        {
            return m_Parameters;
        }
    };

    template< typename T > using ParameterMapPtr = std::shared_ptr< CParameterMap<T> >;
}

#endif //PARAMETERMAP_H
