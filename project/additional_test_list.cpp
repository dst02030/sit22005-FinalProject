#include <iostream>

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"

int main(){
    std::cout<<"Additional Points"<<std::endl;
    std::cout<<"Insert number 1 ~ 10"<<std::endl;
    linkedlist ll;
    int index = 1;
    
    for(index; index <11; index++)
            ll.InsertToBack(index);
    ll.print(std::cout);
    
    std::cout<<"Remove Node which contains 5"<<std::endl;
    ll.RemoveNode(5);
    ll.print(std::cout);
    
    std::cout<<"Insert Node with value 11 next to node which contains value 9"<<std::endl;
    ll.InsertNextTo(9,11);
    ll.print(std::cout);
}