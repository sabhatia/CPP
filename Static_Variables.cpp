#include <iostream>
#include <string>

using namespace std;

void foo()
{
    static int a = 10;
    int b = 20;
    a++;b++;
    cout << "Foo: A = " << a << ", B = " << b << endl;
}

void bar ()
{
    static int a = 100;
    int b = 200;
    a++;b++;
    cout << "Bar: A = " << a << ", B = " << b << endl;
}
int main()
{
    void (*fp1)();
    void (*fp2)();

    fp1 = foo; (*fp1)();
    fp1 = bar; (*fp1)();

    fp2 = foo; fp2();
    fp2 = bar; fp2();



}