#include <iostream>
#include <string>

using namespace std;

// Function to capture the discount logic
double bill_discount (double bill_amount)
{
    if (bill_amount >= 500)
    {
        return 0.8; //20% discount
    }

    if (bill_amount >= 100)
    {
        return 0.9; // 10% discount
    }

    return 1.0; // NO discount
}

// Function to apply discount
double bill_total(double bill_amount)
{
    return bill_amount * bill_discount(bill_amount);
}

// Main: Interact with user
int main()
{
    double in_amount = 0.0;

    cout << "Enter the total bill amount: ";
    cin >> in_amount;
    cout << "Total Bill (after discount): " << bill_total(in_amount) << endl;
}