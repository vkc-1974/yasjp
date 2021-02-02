// File		:yasjp.h
// Author	:Victor Kovalevich
// Created	:Thu Nov  8 17:54:47 2018
#pragma once

#include <string>

namespace yasjp {
enum class ValueType {
    String,
    Number,
    Object,
    Array,
    Bool,
    Null
}

class Value {
public:
    using ValueType_t = ValueType;

    constexpr ValueType_t type() const {
        return typeId_;
    }

protected:
    Value(const ValueType_t typeId)
        : typeId_(typeId) {
    }

    ValueType_t typeId_;
};

template <typename T>
T lexical_cast(const Value& v);

class Array {
public:
    size_t size() const;
    bool empty() const;
    const Value& operator[](const size_t idx) const;
};

class KeyValuePair {
public:
    using Key_t = std::string;
    using Value_t = Value;

    const Key_t& key() const {
        return key_;
    }

    const Value_t& value() const {
        return value_;
    }

protected:
    Key_t key_;
    Value_t value_;
};

class Object {
public:
    using Key_t = std::string;
    using Value_t = Value;

    bool empty() const;
    size_t size() const;
    bool has(const Key_t& key) const;
    const Value_t& operator[](const Key_t& key) const;
};

}  // namespace yasjp
