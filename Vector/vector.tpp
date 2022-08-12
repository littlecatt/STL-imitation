#include "vector.h"

// Constructors
template <typename T>
vector<T>::vector(){
    _size = 0;
    _capacity = 1;
    data_ptr = new T[_capacity];
}
template <typename T>
vector<T>::vector(size_t count, const T &value){
    _size = count;
    _capacity = _size * 2;
    data_ptr = new T[_capacity];
    for (size_t i{0}; i < _size; i++){
        *(data_ptr+i) = value;
    }
}
template <typename T>
vector<T>::vector(std::initializer_list<T> init){
    _size = init.size();
    _capacity = _size * 2;    
    data_ptr = new T[_capacity];
    for (size_t i{0}; i < _size; i++){
        *(data_ptr+i) = *(init.begin()+i);
    }
}
// Copy constructor
template <typename T>
vector<T>::vector(const vector &other){
    _size = other._size;
    _capacity = other._capacity;
    data_ptr = new T[_capacity];
    for (size_t i{0}; i < _size; i++){
        *(data_ptr+i) = *(other.data_ptr+i);
    }
}

template <typename T>
void vector<T>::display(){
    for (size_t i{0}; i < _size; i++){
        std::cout << *(data_ptr+i) << " ";
    }
    std::cout << "\n";
}