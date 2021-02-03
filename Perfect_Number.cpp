#include <iostream>

using namespace std;

int main()
{
    uint user_val = 0;
    uint sum_of_factors = 0;
    cout << "Enter an positive integer: ";
    cin >> user_val;

    for (int factor = 1; factor <= user_val; factor++)
    {
        if (user_val % factor == 0)
        {
            // number is a factor. Add it to the sum.
            sum_of_factors += factor;
        }
    }

    cout << "Sum of factors is: " << sum_of_factors << endl;
    if (sum_of_factors == 2 * user_val)
    {
        cout << user_val << " is a perfect number." << endl;
    }
    else
    {
        cout << user_val << " is NOT a perfect number." << endl;
    }
}