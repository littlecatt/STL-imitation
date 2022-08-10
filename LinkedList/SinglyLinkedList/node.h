#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class Node{
    public:
        T data;
        Node *next;
        Node(): data(0), next(nullptr){};
        Node(T data): data(data), next(nullptr){}
};
#endif