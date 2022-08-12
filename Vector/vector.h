#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

template <typename T>
class vector{
    private:
        T *data_ptr;
        size_t _size;
        size_t _capacity;
    public:
        // Constructors
        vector();
        vector(size_t count, const T &value);
        vector(std::initializer_list<T> init);
        // Copy constructor
        vector(const vector &other);

        // Element access
        T at(size_t pos);
        T operator[](size_t pos);
        T front();
        T back();
        T* data();
        // Capacity
        bool empty();
        size_t size();
        size_t capacity();
        void reserve(size_t new_capacity);
        void shrink_to_fit();
        // Modifiers
        void clear();
        void insert(size_t pos, const T &value);
        void insert(size_t pos, size_t count, const T &value);
        void erase(size_t pos);
        void erase(size_t first, size_t last); // erase in range [first, last)
        void push_back(const T &value);
        void pop_back();
        void resize(size_t count, const T &default_value);
        void swap(vector &other);

        void display();
};

#include "vector.tpp"

#endif