// File		:yasjp.h
// Author	:Victor Kovalevich
// Created	:Thu Nov  8 17:46:54 2018
#pragma once

namespace yasjp
{
namespace impl
{
template <typename ValueType,
          typename ValueTypeContainer,
          ValueType typeId> class ValueImpl final: public Value
{
public:
    using ValueType_t = ValueType;
    
    ValueImpl(const ValueType_t& value)
        : Value(typeId),
          value_(value)
    {
    }

private:
    ValueTypeContainer_t value_;
    
    friend template <typename Type> Type yasjp::lexical_cast(const yasjp::Value& value);
};

namspace containers
{
    

    class NumberContainer
    {
    };

    class ObjectContainer
    {
    };

    class ObjectArrayContainer
    {
    };

    class BoolContainer
    {
    };

    class NullContainer
    {
    };
    
}

}

}
