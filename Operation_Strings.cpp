#include <iostream>
#include <string>

using namespace std;
#define MAX_STR_SIZE 80

void string_tolower(string &in_str, string &lower_str)
{
    for (int indx=0; indx < in_str.length(); indx++)
    {
        lower_str[indx] = (char)tolower((char)in_str[indx]);
    }
}

int main()
{

    string user_str;
    string lower_str;

    user_str.resize(MAX_STR_SIZE);
    lower_str.resize(MAX_STR_SIZE);

    cout << "Enter a string: ";
    getline(cin, user_str);
    cout << "You entered: " << user_str << endl;

    // String Length
    cout << "Length: " << user_str.length() << endl;

    // String Lower
    string_tolower(user_str, lower_str);
    cout << "Lowercase: " << lower_str << endl;
}