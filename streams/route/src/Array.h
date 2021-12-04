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

    T & operator[](size_t idx) {
        return _elements[idx];
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

        T * operator->() {
            return pointer;
        }

        T & operator*() {
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

    template <class Pred>
    void sort(Pred pred) {
        T key; int i, j;
        for (i = 1; i < _size; ++i) {
            key = _elements[i];
            j = i - 1;

            while (j >= 0 && pred(_elements[j], key)) {
                _elements[j + 1] = _elements[j];
                j--;
            }
            _elements[j + 1] = key;
        }
    }
};

#endif