#pragma once

#ifndef _MY_ARRAY_H_
#define _MY_ARRAY_H_

#include <stdexcept>

template <class T, size_t _size>
class Array
{
private:
	T _elements[_size];

public:
	Array() = default;
    ~Array() = default;

    void fill(const T & value) {
        for (size_t i = 0; i < _size; ++i) {
            _elements[i] = value;
        }
    }

    class Iterator
    {
    private:
        T * pointer;
    public:
        Iterator() : pointer(nullptr) {}
        explicit Iterator(T * pointer) : pointer(pointer) {}
        Iterator(const Iterator & iter) : pointer(iter.pointer) {}
        ~Iterator() {}

        Iterator & operator=(const Iterator & iter) {
            pointer = iter.pointer;
            return *this;
        }

        Iterator & operator++() {
            ++pointer;
            return *this;
        }

        Iterator operator++(int) {
            Iterator it(pointer++);
            return it;
        }

        Iterator & operator--() {
            --pointer;
            return *this;
        }

        bool operator!=(const Iterator & iter) {
            return pointer != iter.pointer;
        }

        bool operator<(const Iterator & iter) {
            return pointer < iter.pointer;
        }

        bool operator>(const Iterator & iter) {
            return pointer > iter.pointer;
        }

        bool operator==(const Iterator & iter) {
            return pointer == iter.pointer;
        }

        ValueType & operator*() {
            return *pointer;
        }
    };

    Iterator begin() { return Iterator(_elements); }
    Iterator end() { return Iterator(_elements + _size); }

    size_t size() const {
        return _size;
    }

    const T * data() const {
        return _elements;
    }

};

#endif