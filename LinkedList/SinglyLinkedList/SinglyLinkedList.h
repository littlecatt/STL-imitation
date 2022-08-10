#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include "node.h"

template <typename T>
class SinglyLinkedList{
    private:
        Node<T> *head;
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        // Capacity
        bool empty();
        // Element access
        T front();
        // Modifiers
        void push_front(T data);
        void pop_front();
        //void emplace_front(Arg?)
        void insert_after(T data, Node<T>* target_node);
        void insert_before(T data, Node<T>* target_node);
        void erase_after(Node<T>* target_node); 
        void swap(SinglyLinkedList &src); 
        void clear(); 
        
        // Operations
        Node<T>* find(T target_data);
        void reverse(); 
        void sort(); // not yet implemented

        void display() const;
}; 

#include "SinglyLinkedList.tpp"

#endif

