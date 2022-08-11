#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

int main(){
    DoublyLinkedList<std::string> customers;
    customers.push_back("jojo");
    customers.push_front("john");
    customers.insert_after("jack", customers.find("jojo"));
    customers.insert_before("jimmy", customers.find("jojo"));
    customers.display();
    customers.reverse();
    customers.display();
    std::cout << "size: " << customers.size() << "\n";
    std::cout << "removing items ...\n";
    customers.remove_if([](std::string s){return s.size() == 4;});
    std::cout << "size: " << customers.size() << "\n";
    customers.display();
}