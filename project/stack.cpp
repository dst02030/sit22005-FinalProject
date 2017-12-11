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
   
}

void stack::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|";
    ll.print(os);
    std::cout << "-----------------------------------" << std::endl;
}