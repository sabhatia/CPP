#include <iostream>
#include "Stack.h"

int main()
{
    Stack s1;
    cout << "Stack Size: " << s1.get_size() << endl;
    
    cout << "S1(1): " << s1 << endl;
    s1.push(10); s1.push(20);
    cout << "S1(2): " << s1 << endl;
    cout << "S1 Popped: " << s1.pop() << endl;
    s1.pop(); s1.pop();
    cout << "S1(3): " << s1 << endl;
}
 