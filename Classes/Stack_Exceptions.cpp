#include <iostream>
#include <string>

using namespace std;

// A class that allows for push and pop operations on integers
// The underlying data structure used is an array
class Stack
{
    private:
        static const u_int STACK_SIZE_DEFAULT = 5;
        static const u_int STACK_SIZE_MAX     = 20;
        static const u_int STACK_SIZE_MIN     = 5;
        u_int stack_size;
    public:
        Stack(u_int init_stack_size = STACK_SIZE_DEFAULT);

};

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
}

int main()
{

}