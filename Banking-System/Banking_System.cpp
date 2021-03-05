#include "Bank_Account_Test.cpp"

void print_banking_banner()
{
    cout << "=====================================================" << endl;
    cout << "\t\tWelcome to Sandeep Bank" << endl;
    cout << "=====================================================" << endl;
}

void print_banking_menu()
{
    cout << "Select from the following options:" << endl;
    cout << "1: Open  an account" << endl;
    cout << "2: Close an account" << endl;
    cout << "3: Show all account(s)" << endl;
    cout << "4: Account Balance Inquiry" << endl;
    cout << "5: Deposit  funds" << endl;
    cout << "6: Withdraw funds" << endl;
    cout << "7: Quit" << endl; 
}

u_int get_banking_option()

{
    u_int selected_banking_option;
    cout << "Your selection: ";
    cin >> selected_banking_option;
    return (selected_banking_option);
}

int main()
{
    u_int banking_option = 0;

    print_banking_banner();
    print_banking_menu();
    banking_option = get_banking_option();
    cout << "Selected Option: " << banking_option << endl;

}