// File		:NumberContainer.h
// Author	:Victor Kovalevich
// Created	:Thu Nov  8 19:56:17 2018
#pragma once

namespace yasjp
{
namespace impl
{
namespace containers
{
template <class T> class NumberContainer
{
public:
    NumberContainer(const T number)
        : number_(number)
    {
    }

private:
    T number_;
};

}

}

}
