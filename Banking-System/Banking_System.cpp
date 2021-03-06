#ifndef BANKING_SYSTEM_CPP_
#define BANKING_SYSTEM_CPP_
#include <vector>
#include "Bank_Account.cpp"

class Banking_System
{
private:
    vector<Bank_Account> accounts_vct;
public:
    static void print_banking_banner()
    {
        cout << "=====================================================" << endl;
        cout << "\t\tWelcome to Sandeep Bank" << endl;
        cout << "=====================================================" << endl;
    }

    static void print_banking_menu()
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

    static u_int get_banking_option()
    {
        u_int selected_banking_option;
        cout << "Your selection: ";
        cin >> selected_banking_option;
        return (selected_banking_option);
    }
};

#endif /* BANKING_SYSTEM_CPP_ */