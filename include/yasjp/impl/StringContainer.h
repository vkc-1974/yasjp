// File		:StringContainer.h
// Author	:Victor Kovalevich
// Created	:Thu Nov  8 19:55:10 2018
#pragma once

namespace yasjp
{
namespace impl
{
namespace containers
{
using StringContainer = std::string;

}

using ValueString = ValueImpl<std::string, containers::StringContainer, ValueType::String>;

}

}
