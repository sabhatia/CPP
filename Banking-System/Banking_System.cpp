#ifndef BANKING_SYSTEM_CPP_
#define BANKING_SYSTEM_CPP_

#include <vector>
#include "Banking_DB.cpp"

enum BANKING_OPTIONS
{
    SB_OPTION_NONE = 0, 
    SB_OPTION_OPEN_ACCOUNT,
    SB_OPTION_CLOSE_ACCOUNT,
    SB_OPTION_SHOW_ACCOUNTS,
    SB_OPTION_SHOW_BALANCE,
    SB_OPTION_DEPOSIT_FUNDS,
    SB_OPTION_WITHDRAW_FUNDS,
    SB_OPTION_QUIT_BANKING
};
class Banking_System
{
private:
    vector<Bank_Account> accounts_vct;
    Banking_DB bank_db;
    string bank_name;
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

    static BANKING_OPTIONS get_banking_option()
    {
        u_int selected_banking_option;
        cout << "Your selection: ";
        cin >> selected_banking_option;
        return ((BANKING_OPTIONS)selected_banking_option);
    }

    Banking_System(string bank_name, string db_path):bank_db(db_path, &this->accounts_vct)
    {
        // create the vector - this will be removed
        this->bank_name = bank_name;
        //this->bank_db(db_path, &this->accounts_vct);
        this->bank_db.initialize(); 
    }

    string get_name()
    {
        return (this->bank_name);
    }

    void process_option(BANKING_OPTIONS banking_option)
    {
        switch(banking_option)
        {
            case SB_OPTION_OPEN_ACCOUNT:
                process_open_account();
                break;
            case SB_OPTION_CLOSE_ACCOUNT:
                process_close_account();
                break;
            case SB_OPTION_SHOW_ACCOUNTS:
                process_list_accounts();
                break;
            default:
                cout << "ERROR: Unknown selection[" << banking_option << "]\n";
        }
    }

    void process_open_account()
    {
        u_int account_id;
        u_int owner_id;
        float initial_amt;
        cout << "Thanking for opening a new account\nPlease enter following details\n";
        cout << "\tAccount ID:"; cin >> account_id;
        cout << "\tOwner ID: "; cin >> owner_id;
        cout << "\tInitial Funds: "; cin >> initial_amt;

        this->bank_db.create_new_account(account_id, owner_id, initial_amt);
    }

    void process_close_account()
    {
        u_int account_id;

        cout << "Close Account Details\n";
        cout << "\tAccount ID: "; cin >> account_id;

        this->bank_db.close_existing_account(account_id);
    }

    void process_list_accounts()
    {
        cout << "============= Opened Accounts ==============" << endl;
        this->bank_db.list_open_accounts();
        cout << "============= Closed Accounts ==============" << endl;
        this->bank_db.list_closed_accounts();
    }

};

#endif /* BANKING_SYSTEM_CPP_ */