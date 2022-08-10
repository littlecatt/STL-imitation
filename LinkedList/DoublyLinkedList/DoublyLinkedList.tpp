#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : _front(nullptr), _back(nullptr){
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    std::cout << "Doubly Linked List out of scope, evoking destructor...\n";
    Node<T> *curr = _front;
    _front = nullptr;
    _back = nullptr;
    while(curr != nullptr){
        // save temp
        Node<T> *temp = curr->next;
        // delete curr
        delete curr;
        // move on to next node
        curr = temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::display() const{
    Node<T> *temp = _front;
    while(temp != nullptr){
        std::cout << temp << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Capacity
template <typename T>
bool DoublyLinkedList<T>::empty(){
    return _front == nullptr;
}
template <typename T>
size_t DoublyLinkedList<T>::size(){
    return _size;
}
// Element access
template <typename T>
T DoublyLinkedList<T>::front(){
    return _front->data;
}
template <typename T>
T DoublyLinkedList<T>::back(){
    return _back->data;
}

// Modifiers
template <typename T>
void DoublyLinkedList<T>::push_front(T data){
    Node<T> *new_node = new Node<T>(data);
    // empty at first
    if (_front == nullptr){
        _front = new_node;
        _back = new_node;
    } else{
        // link
        new_node->next = _front;
        _front->prev = new_node;
        // re-assign
        _front = new_node;
    }
}
template <typename T>
void DoublyLinkedList<T>::pop_front(){
    // empty
    if (_front == nullptr){
        return;
    }
    // one-node
    else if (_front == _back){
        delete _front;
        _front = nullptr;
        _back = nullptr;
    }
    else {
        // record next 
        Node<T> *second = _front->next;
        second->prev = nullptr;
        delete _front;
        _front = second;
    }
}
template <typename T>
void DoublyLinkedList<T>::push_back(T data){
    Node<T> *new_node = new Node<T> (data);
    // empty at first
    if (_front == nullptr){
        _front = new_node;
        _back = new_node;
    } else{
        // link
        new_node->prev = _back;
        _back->next = new_node;
        // re-assign
        _back = new_node;
    }
}
template <typename T>
void DoublyLinkedList<T>::pop_back(){
    // empty
    if (_front == nullptr){
        return;
    }
    // one-node
    else if (_front == _back){
        delete _back;
        _front = nullptr;
        _back = nullptr;
    }
    else {
        // record next 
        Node<T> *second = _back->prev;
        second->next = nullptr;
        delete _back;
        _back = second;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert_after(T data, Node<T>* target_node){
    // target node is the back node
    if (target_node == _back){
        this->push_back(data);    
        return;
    }
    Node<T> *new_node = new Node<T> (data);
    Node<T> *temp = target_node->next;
    // relink
    target_node->next = new_node;
    new_node->prev = target_node;
    new_node->next = temp;
    temp->prev = new_node;
}
template <typename T>
void DoublyLinkedList<T>::insert_before(T data, Node<T>* target_node){
    // target node is the front node
    if (target_node == _front){
        this->push_front(data);    
        return;
    }
    Node<T> *new_node = new Node<T> (data);
    Node<T> *temp = target_node->prev;
    // relink
    target_node->prev = new_node;
    new_node->next = target_node;
    new_node->prev = temp;
    temp->next = new_node;
}
template <typename T>
void DoublyLinkedList<T>::erase(Node<T>* target_node){
    // erase front node
    if (target_node == _front){
        this->pop_front();
        return;
    }
    // erase back node
    if (target_node == _back){
        this->pop_back();
        return;
    }
    // middle nodes
    Node<T> *prev_node = target_node->prev;
    Node<T> *next_node = target_node->next;
    prev_node->next = next_node;
    next_node->prev = prev_node;
    delete target_node;
} 

template <typename T>
void DoublyLinkedList<T>::swap(DoublyLinkedList &src){
    // temps
    Node<T> *temp_front = _front;
    Node<T> *temp_back = _back;
    size_t temp_size = _size;
    // swap
    _front = src._front;
    _back = src._back;
    _size = src._size;
    src._front = temp_front;
    src._back = temp_back;
    src._size = temp_size;
}
template <typename T>
void DoublyLinkedList<T>::clear(){
    Node<T> *curr = _front;
    _front = nullptr;
    _back = nullptr;
    while(curr != nullptr){
        // save temp
        Node<T> *temp = curr->next;
        // delete curr
        delete curr;
        // move on to next node
        curr = temp;
    }
}