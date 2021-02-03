#include <iostream>

using namespace std;

bool is_leap_year(int year)
{
    if (((year % 400) == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return true;
    }
    return false;
}

int main()
{
    uint year_val;

    cout << "Enter the year: ";
    cin >> year_val;

    if (is_leap_year(year_val))
    {
        cout << year_val << " is a leap year." << endl;
    }
    else
    {
        cout << year_val << " is NOT a leap year." << endl;
    }
}