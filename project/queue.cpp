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
    int temp = 0;
    if(!isEmpty())
    {
        Node* cur = get_head();
        IntegerNode* inode = static_cast<IntegerNode*>(cur);
        temp = inode -> get_value();
    }
    return temp;
    
}

void queue::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    linkedlist::print(os);
    std::cout << "-----------------------------------" << std::endl;
}