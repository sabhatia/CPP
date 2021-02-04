#include <iostream>
#include <string>

using namespace std;
#define MAX_STR_SIZE 80

int main()
{

    string user_str;
    user_str.reserve(MAX_STR_SIZE);

    //char user_buf[80];

    cout << "Enter a string: ";
    getline(cin, user_str);
    cout << "You entered: " << user_str << endl;

    // String Operations
    cout << "String Length: " << user_str.length() << endl;
}