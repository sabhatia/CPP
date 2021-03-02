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
    T* s_arry;
    int s_ptr = 0;

public:
    Stack_Template(int size = 10)
    { 
        s_arry = new T[size];
    }

    ~Stack_Template()
    {
        delete [] s_arry;
    }

    void push(T elem)
    {
        return;
    }
    T pop()
    {
        T elem;
        return (elem);
    }
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