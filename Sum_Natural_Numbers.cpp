#include <iostream>
#include <string>

using namespace std;

int main()
{
    string last_number_str;
    int last_number = 0, sum = 0;

    cout << "Enter the last natural number: ";
    getline(cin, last_number_str);
    last_number = stoi(last_number_str);

    // Find the sum and print
    sum = (last_number * (last_number + 1))/2;
    cout << "Sum of numbers till " << last_number << " is: " << sum << endl;
}