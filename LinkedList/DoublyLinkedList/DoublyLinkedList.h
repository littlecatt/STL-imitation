#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "node.h"

template <typename T>
class DoublyLinkedList{
    private:
        Node<T> *_front;
        Node<T> *_back;
        size_t _size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        // Capacity
        bool empty();
        size_t size();
        // Element access
        T front();
        T back();
        // Modifiers
        void push_front(T data);
        void pop_front();
        void push_back(T data);
        void pop_back();
        //void emplace_front(Arg?)
        void insert_after(T data, Node<T>* target_node);
        void insert_before(T data, Node<T>* target_node);
        void erase(Node<T>* target_node); 
        void swap(DoublyLinkedList &src); 
        void clear(); 
        
        // Operations
        Node<T>* find(const T &target_data);
        void reverse(); 
        void sort(); 
        size_t remove(const T &data);

        template <typename UnaryPredicate> 
        size_t remove_if(UnaryPredicate p);

        void display() const;
}; 

#include "DoublyLinkedList.tpp"

#endif

