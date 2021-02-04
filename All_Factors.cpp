#include <iostream>

using namespace std;

int main()
{
    uint user_val = 0;
    char prompt[] = "Enter a positive integer: ";

    cout << prompt;
    cin >> user_val;

    for (int factor = 1; factor <= user_val; factor++)
    {
        if (user_val % factor == 0)
        {
            cout << factor << " is a factor." << endl;
        }
    }

}