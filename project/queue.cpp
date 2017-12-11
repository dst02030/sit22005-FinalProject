#include "queue.h"

void queue::push(int val)
{
    InsertToBack(val);
}

int queue::pop()
{

    RemoveFromFront_Integer();
}

int queue::front()
{
    
    
}

void queue::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    linkedlist::print(os);
    std::cout << "-----------------------------------" << std::endl;
}