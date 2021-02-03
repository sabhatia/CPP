#include <iostream>
#include <string>

using namespace std;
#define MAX_STR_LEN 80

int main()
{
    string line_string;
    cout << "Please enter your name: ";
    getline(cin, line_string);
    cout << "You entered: " << line_string << "\n";
}