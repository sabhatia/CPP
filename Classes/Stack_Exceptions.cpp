#include <iostream>
#include <string>
#include "Stacks.h"

using namespace std;

Stack::Stack (u_int init_stack_size)
{
    if (init_stack_size < Stack::STACK_SIZE_MIN || init_stack_size > Stack::STACK_SIZE_MAX)
    {
        this->stack_size = STACK_SIZE_DEFAULT;
    } 
    else
    {
        this->stack_size = init_stack_size;
    }
    stack_array = new int[this->stack_size];
    stack_depth = 0;
}

u_int Stack::get_size()
{
    return (this->stack_size);
}

ostream& operator<< (ostream& console, Stack& s)
{
    console << "Stack" << endl;
    console << "-----" << endl;
    console << "\tDepth: " << s.stack_depth << endl;
    console << "\tSize : " << s.stack_size << endl;
    console << "\tContents: ";
    for (int indx = 0; indx < s.stack_depth; indx++)
    {
        console << s.stack_array[indx] << " ";
    }

    return (console);
}

void Stack::push(int elem_val)
{
    if (this->stack_depth == this->stack_size)
    {
        return;
    }
    this->stack_array[this->stack_depth++] = elem_val;
}

int Stack::pop (void)
{
    if (this->stack_depth) 
    {
        return (this->stack_array[--stack_depth]);
    }

    return (0);
}

int main()
{
    Stack s1;
    cout << "Stack Size: " << s1.get_size() << endl;
    
    cout << "S1(1): " << s1 << endl;
    s1.push(10); s1.push(20);
    cout << "S1(2): " << s1 << endl;
    cout << "S1 Popped: " << s1.pop() << endl;
    s1.pop(); s1.pop();
    cout << "S1(3): " << s1 << endl;
}