#include "Stack_Template.hpp"

using namespace std;

int main()
{
    Stack_Template<int> s1;
    Stack_Template<float> s2;

    // TC(1): Basic Push
    s1.push(10); s1.push(20); s1.push(30);
    s2.push(11.11); s2.push(22.22); s2.push(33.33);
    cout << s1; cout << s2;

    // TC(2): Basic Pop
    s1.pop(); s2.pop();
    cout << s1; cout << s2;

    s1.pop(); s2.pop();
    cout << s1; cout << s2;

}