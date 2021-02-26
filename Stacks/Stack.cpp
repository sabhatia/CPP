#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"

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
        string err_msg = "Stack Full"; 
         throw (Stack_Exception(101, err_msg));
    }
    
    this->stack_array[this->stack_depth++] = elem_val;
}

int Stack::pop (void)
{
    if (!this->stack_depth)
    {
        string err_msg = "Stack Empty.";
        throw (Stack_Exception(101, err_msg));
    }
    
    return (this->stack_array[--stack_depth]);
}

Stack_Exception::Stack_Exception(u_int error_code, string& error_msg)
{
    this->err_msg = error_msg;
    this->err_code = error_code;
}

const char* Stack_Exception::what()
{
    return (this->err_msg.c_str());
}