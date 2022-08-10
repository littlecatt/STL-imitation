#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

int main(){
    DoublyLinkedList<std::string> customers;
    customers.push_back("jojo");
    customers.push_front("john");
    customers.display();
    customers.clear();
    customers.display();
}