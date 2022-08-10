#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
template <typename T>
class Node{
    public:
        T data;
        Node *next;
        Node *prev;
        Node(T data): data(data), next(nullptr), prev(nullptr){}
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Node<T> *n){
    os << n->data;
    return os; 
}
#endif
