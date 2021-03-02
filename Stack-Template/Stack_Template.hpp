#ifndef STACKS_TEMPLATE_HPP
#define STACKS_TEMPLATE_HPP

#endif // STACKS_TEMPLATE_HPP

#include <iostream>
#include <string>

template <class T>

class Stack_Template
{
    private:
        T s_arry[10];
        int s_ptr = 0;
    public:
        void push(T elem);
        T pop();
};