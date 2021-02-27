#include <iostream>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

// A class that allows for push and pop operations on integers
// The underlying data structure used is an array
class Stack
{
    private:
        // Constants for Standard Operation
        static const u_int STACK_SIZE_DEFAULT = 5;
        static const u_int STACK_SIZE_MAX     = 20;
        static const u_int STACK_SIZE_MIN     = 5;

        // Internal data structure related declarations
        u_int stack_depth = 0;
        u_int stack_size;
        int* stack_array;   // dynamically allocated array

    public:

        // Constants for Error conditions
        static const u_int STACK_ERROR_OVERFLOW = 101;
        static const u_int STACK_ERROR_UNDERFLOW = 102;

        // Stack API
        Stack(u_int init_stack_size = STACK_SIZE_DEFAULT);
        //TO-DO: ~Stack();
        u_int get_size ();
        void push (int elem_val);
        int pop (void);
        friend ostream& operator<< (ostream& console, Stack& s);
};

class Stack_Exception: public std::exception
{
    private:
        u_int err_code;
        string err_str;
        string err_msg; // Error Message = Error code + Error String
        stringstream err_stream;
    public:
        Stack_Exception(u_int stack_err_code, string& stack_err_msg);
        virtual const char* what();
};

