#include <iostream>

using namespace std;

int main()
{
    uint user_val = 0;
    cout << "Enter an positive integer: ";
    cin >> user_val;

    for (int factor = 1; factor <= user_val; factor++)
    {
        if (user_val % factor == 0)
        {
            cout << factor << " is a factor." << endl;
        }
    }

}