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
        u_int stack_depth = 0;
    public:
        Stack(u_int init_stack_size = STACK_SIZE_DEFAULT);
        u_int get_size ();
        void push (int elem_val);
        int pop (void);
        friend ostream& operator<< (ostream& console, Stack& s);
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
    stack_depth = 0;
}

u_int Stack::get_size()
{
    return (this->stack_size);
}

ostream& operator<< (ostream& console, Stack& s)
{
    console << "Stack Contents: ";
    for (int indx = 0; indx < s.stack_depth; indx++)
    {
        console << s.stack_array[indx] << " ";
    }

    return (console);
}

void Stack::push(int elem_val)
{
    return;
}

int Stack::pop (void)
{
    return 0;
}

int main()
{
    Stack s1;
    cout << "Stack Size: " << s1.get_size() << endl;
    
    cout << "S1(1): " << s1 << endl;
    s1.push(10);
    cout << "S1(2): " << s1 << endl;
    cout << "S1 Popped: " << s1.pop() << endl;
    cout << "S1(3): " << s1 << endl;
}