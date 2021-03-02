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
    T s_arry[10];
    int s_ptr = 0;

public:

    void push(T elem);
    T pop();
    friend ostream &operator<<(ostream &console, Stack_Template<T> &st)
    {

        console << "Contents:";
        for (int indx = 0; indx < st.s_ptr; indx++)
        {
            console << "[" << indx << "]"
                    << " " << st.s_arry[indx] << " ";
        }
        console << endl;

        return (console);
    }
};