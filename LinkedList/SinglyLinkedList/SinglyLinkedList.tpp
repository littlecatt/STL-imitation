#include <iostream>
#include "SinglyLinkedList.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head(nullptr){
}
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    std::cout << "Singly Linked List out of scope, evoking destructor...\n";
    Node<T> *curr = head;
    while(curr != nullptr){
        Node<T> *temp = curr->next;
        delete(curr);
        curr = temp;
    }
}

// Capacity
template<typename T>
bool SinglyLinkedList<T>::empty(){
    return head == nullptr;
}
// Element access
template<typename T>
T SinglyLinkedList<T>::front(){
    return head->data;
}

// Modifiers
template <typename T>
void SinglyLinkedList<T>::push_front(T data){
    // empty
    if (head == nullptr){
        head = new Node<T>(data);
    } else{
        Node<T> *temp = new Node<T>(data);
        temp->next = head;
        head = temp;
    }
}
template <typename T>
void SinglyLinkedList<T>::pop_front(){
    // empty
    if (head == nullptr){
        std::cout << "List is already empty, cannot pop" << std::endl;
    } else{
        Node<T> *temp = head->next;
        delete(head);
        head = temp;
    }
}
template <typename T>
Node<T>* SinglyLinkedList<T>::find(T target_data){
    /**
     * Find the target data by searching along the list 
     * Input: target_data (T)
     * Return: index (int)
     */
    Node<T> *curr = head;
    while(curr != nullptr){
        if (curr->data == target_data)
            return curr; 
        else
            curr = curr->next;
    }
    return nullptr;
}
template <typename T>
void SinglyLinkedList<T>::insert_after(T data, Node<T> *target_node){
    // save original next node
    Node<T> *temp = target_node->next;
    // new node
    Node<T> *new_node = new Node<T>(data);
    // insert 
    target_node->next = new_node;
    // re-link
    new_node->next = temp; 
}

template <typename T>
void SinglyLinkedList<T>::insert_before(T data, Node<T> *target_node){
    /**
     * Because it's a singly linked list, we don't have 
     * information about previous node of target node, so 
     * we have to do the insert in a 'swapping data' way
     */ 
    T old_data = target_node->data;
    // swap
    target_node->data = data;
    this->insert_after(old_data, target_node);
}

template <typename T>
void SinglyLinkedList<T>::erase_after(Node<T> *target_node){
    // save original next next node
    Node<T> *temp = target_node->next->next;
    // erase node
    delete target_node->next;
    // re-link
    target_node->next = temp; 
}

template <typename T>
void SinglyLinkedList<T>::swap(SinglyLinkedList &src){
    // save head
    Node<T> *temp = this->head;
    // exchange head
    this->head = src.head;
    src.head = temp;
}

template <typename T>
void SinglyLinkedList<T>::clear(){
    // null out head
    Node<T> *curr = head->next;
    head = nullptr;
    while(curr != nullptr){
        Node<T> *temp = curr->next;
        delete curr;
        curr = temp;
    }
}


// Operation
template <typename T>
void SinglyLinkedList<T>::display() const{
    Node<T>* current = head;
    while(current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
template <typename T>
void SinglyLinkedList<T>::reverse(){
    // sliding window of 3 nodes
    Node<T> *curr = head;
    Node<T> *temp = curr->next;
    Node<T> *prev = nullptr;
    while(curr != nullptr){
        // relink
        temp = curr->next; 
        curr->next = prev;
        // update window
        prev = curr;
        curr = temp;
    }
    head = prev;
}