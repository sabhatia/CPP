#ifndef STACKS_TEMPLATE_HPP
#define STACKS_TEMPLATE_HPP

#endif // STACKS_TEMPLATE_HPP

#include <iostream>

using namespace std;
template <class T>
class Stack_Template
{
private:
    T* s_arry;
    int s_ptr = 0;
    u_int size = 10;
public:
    Stack_Template(int size = 10)
    { 
        this->size = size;
        s_arry = new T[size];
    }

    ~Stack_Template()
    {
        delete [] s_arry;
    }

    void push(T elem)
    {
        if (s_ptr >= size) 
        {
            return;
        }
        s_arry[s_ptr++] = elem;
    }

    T pop()
    {
        T error_elem;

        if (s_ptr == 0)
        {
            return error_elem;
        }
        return (s_arry[s_ptr--]);
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