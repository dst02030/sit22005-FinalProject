#include "stack.h"

void stack::push(int val)
{
    ll.InsertToBack(val);
}

int stack::pop()
{
    ll.RemoveFromBack_Integer();
}

int stack::top()
{
   int temp = 0;
   Node* cur = ll.get_head();

    if(!ll.isEmpty())
    {
        if(cur->get_next() == nullptr)
        {
            IntegerNode* inode = static_cast<IntegerNode*>(ll.get_head());
            temp = inode->get_value();
        }
        else
        {
            IntegerNode* inode = static_cast<IntegerNode*>(ll.find_prev_node(nullptr));
            temp = inode -> get_value();

        }
    }

    return temp;
}

void stack::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|";
    ll.print(os);
    std::cout << "-----------------------------------" << std::endl;
}