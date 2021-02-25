#include <iostream>

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
        u_int stack_depth = 0;
    public:
        Stack(u_int init_stack_size = STACK_SIZE_DEFAULT);
        u_int get_size ();
        void push (int elem_val);
        int pop (void);
        friend ostream& operator<< (ostream& console, Stack& s);
};
