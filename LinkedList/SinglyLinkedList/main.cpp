#include <iostream>
#include "node.h"
#include "SinglyLinkedList.h"

int main(){
    Node<int> n{2};
    std::cout << n.data << std::endl;
    SinglyLinkedList<int> ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.insert_after(10, ll.find(2));
    ll.insert_after(12, ll.find(2));
    ll.insert_before(20, ll.find(12));
    ll.erase_after(ll.find(3));
    ll.display();
    ll.reverse();
    ll.display();
    ll.clear();
    ll.display();
}