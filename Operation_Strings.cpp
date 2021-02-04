#include <iostream>
#include <string>

using namespace std;
#define MAX_STR_SIZE 80

void string_tolower(string &in_str, string &buffer_str)
{
    for (int indx=0; indx < in_str.length(); indx++)
    {
        buffer_str[indx] = (char)tolower((char)in_str[indx]);
    }
}

void string_toupper(string &in_str, string &buffer_str)
{
    for (int indx=0; indx < in_str.length(); indx++)
    {
        buffer_str[indx] = (char)toupper((char)in_str[indx]);
    }
}
int main()
{

    string user_str;
    string buffer_str;

    user_str.resize(MAX_STR_SIZE);
    buffer_str.resize(MAX_STR_SIZE);

    cout << "Enter a string: ";
    getline(cin, user_str);
    cout << "You entered: " << user_str << endl;

    // String Length
    cout << "Length: " << user_str.length() << endl;

    // String Lower
    string_tolower(user_str, buffer_str);
    cout << "Lowercase: " << buffer_str << endl;
     
    // String Upper
    string_toupper(user_str, buffer_str);
    cout << "Uppercase: " << buffer_str << endl;
}