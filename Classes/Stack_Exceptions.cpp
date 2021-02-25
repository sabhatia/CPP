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
        int *stack_array;
    public:
        Stack(u_int init_stack_size = STACK_SIZE_DEFAULT);
        u_int get_size ();
        void push (int elem_val);
        int pop (void);
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
    stack_array = new int[this->stack_size];
}

u_int Stack::get_size()
{
    return (this->stack_size);
}

int main()
{
    Stack s1;
    cout << "Stack Size: " << s1.get_size() << endl;
}