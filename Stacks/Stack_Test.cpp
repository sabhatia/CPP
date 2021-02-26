#include <iostream>
#include "Stack.h"

int main()
{
    Stack s1;
    cout << "Stack Size: " << s1.get_size() << endl;
    
    cout << "S1(1): " << s1 << endl;
    try {
        s1.push(10); s1.push(20); s1.push(30); s1.push(40); s1.push(50); s1.push(60); s1.push(70);
    }
    catch (Stack_Exception& se)
    {
        cout << se.what() << endl;
        //cout << "ERROR (" << stack_exception << "): Could not push element. Stack full" << endl;
    }

    // Let's make sure we know what the stack looks like
    cout << "S1(2): " << s1 << endl;
    try {
        cout << "S1 Popped: " << s1.pop() << endl;
        s1.pop(); s1.pop();
        s1.pop(); s1.pop();
        s1.pop(); s1.pop();
        s1.pop(); s1.pop();
    }
    catch (Stack_Exception& se)
    {
        cout << se.what() << endl;
        //cout << "ERROR (" << stack_exception << "): Could not pop element. Stack empty. " << endl;
    }

    // Let's make sure we know what the stack looks like
    cout << "S1(3): " << s1 << endl;
}
 