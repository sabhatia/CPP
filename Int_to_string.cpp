#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string dummy_str;
    int i = 100;
    stringstream ss;

    ss << i;

    dummy_str = "Hello world ";
    cout << dummy_str + ss.str() << endl;

}