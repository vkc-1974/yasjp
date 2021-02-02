// File		:Cast.cpp
// Author	:Victor Kovalevich
// Created	:Thu Nov  8 20:01:03 2018
#include "yasjp/impl/yasjp.h"

namespace yasjp {
using ValueString = yasjp::impl::ValueImpl<std::string, yasjp::impl::containers::StringContainer>;

template <> std::string lexical_cast<std::string>(const yasjp::Value& v) {
    switch (v.type()) {
        case ValueType::String:
            return dynamic_cast<const yasjp::impl::ValueString&>(v).value_;

        case ValueType::Number:
            return std::string(dynamic_cast<const yasjp::impl::ValueNumber&>(v).value_);

        case ValueType::Object:
            return std::string(dynamic_cast<const yasjp::impl::ValueObject&>(v).value());

            // case ValueType::Bool:
            //     return std::string(dynamic_cast<const yasjp::impl::ValueBool&>(v).value() ? "true" : "false");

            // case ValueType::Null:
            //     return std::string("");

        default:
            throw std::runtime_error("Unsupported casting");
    }
}

template <> std::int64_t lexical_cast<std::int64_t>(const yasjp::Value& v) {
    switch (v.type()) {
        case ValueType::String:
            return std::stoi(dynamic_cast<const yasjp::impl::ValueString&>(v).value_);

        case ValueType::Number:
            return int64_t(dynamic_cast<const yasjp::impl::ValueNumber&>(v).value_);

            // case ValueType::Object:
            //     return int64_t(dynamic_cast<const yasjp::impl::ValueObject&>(v).value());

            // case ValueType::Bool:
            //     return std::string(dynamic_cast<const yasjp::impl::ValueBool&>(v).value() ? "true" : "false");

            // case ValueType::Null:
            //     return std::string("");

        default:
            throw std::runtime_error("Unsupported casting");
    }
}

template <> bool lexical_cast<bool>(const yasjp::Value& v) {
    switch (v.type()) {
            // case ValueType::String:
            //     return std::stoi(dynamic_cast<const yasjp::impl::ValueString&>(v).value_);

            // case ValueType::Number:
            //     return int64_t(dynamic_cast<const yasjp::impl::ValueNumber&>(v).value_);

            // case ValueType::Object:
            //     return int64_t(dynamic_cast<const yasjp::impl::ValueObject&>(v).value());

        case ValueType::Bool:
            return std::string(dynamic_cast<const yasjp::impl::ValueBool&>(v).value() ? "true" : "false");

            // case ValueType::Null:
            //     return std::string("");

        default:
            throw std::runtime_error("Unsupported casting");
    }
}

}  // namespace yasjp
