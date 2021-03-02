#ifndef STACKS_TEMPLATE_HPP
#define STACKS_TEMPLATE_HPP

#endif // STACKS_TEMPLATE_HPP

#include <iostream>
#include <string>

using namespace std;
template <class T>
class Stack_Template
{
private:

    int s_ptr = 0;

public:
    T s_arry[10];
    void push(T elem);
    T pop();
    friend ostream &operator<<(ostream &console, const Stack_Template<T> &st);
};

template <class T>
void Stack_Template<T>::push(T elem)
{
    return;
}

template <class T>
T Stack_Template<T>::pop()
{
    T elem;
    return (elem);
}

template <class T>
ostream &operator<<(ostream &console, Stack_Template<T> &st)
{
    console << "Stack Contents:";
    for (int indx = 0; indx < 10; indx++)
    {
        console << "[" << indx << "]"
                << " " << st.s_arry[indx] << " ";
    }

    return (console);
}
