#ifndef BANK_ACCOUNT_CPP_
#define BANK_ACCOUNT_CPP_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank_Account
{
private:
    u_int account_id;
    u_int owner_id;
    float available_funds;
    bool is_open;

public:

    static const u_int MINIMUM_BALANCE = 500.00;

    Bank_Account(u_int account_id = 0, u_int owner_id = 0,
                 float available_funds = 0.0, bool is_open = false)
    {
        this->account_id = account_id;
        this->owner_id = owner_id;
        this->available_funds = available_funds;
        this->is_open = is_open;
    }

    // Accessor methods
    u_int get_account_id()
    {
        return this->account_id;
    }

    float get_funds()
    {
        return this->available_funds;
    }

    u_int get_owner_id()
    {
        return this->owner_id;
    }

    bool is_open_account()
    {
        return this->is_open;
    }

    void close_account()
    {
        this->is_open = false;
    }

    // Funds operations
    float deposit_funds(float additional_funds)
    {
        if (!is_open)
        {
            // Can't deposit in closed accounts
            cout << "ERROR: Account is closed. Deposit cancelled" << endl;
        } 
        else{
            available_funds += additional_funds;
        }
        return (available_funds);
    }

    float withdraw_funds(float removed_funds)
    {
        float enforced_balance = MINIMUM_BALANCE;
        if (!is_open)
        {
            // Closed account. No minimum balance needed
            enforced_balance = 0.0;
        }
        if (available_funds < removed_funds + enforced_balance)
        {
            cout << "ERROR: Not enough funds. Current balance: " << available_funds << ".\n";
        } 
        else
        {        
            available_funds -= removed_funds;
        }
        return (available_funds);
    }

    // IO Routines
    friend ostream &operator<<(ostream &console, Bank_Account ba)
    {
        console << "Account Details:" << endl;
        console << "\tID: " << ba.account_id << endl;
        console << "\tOwner: " << ba.owner_id << endl;
        console << "\tFunds:" << ba.available_funds << endl;
        console << "\tStatus: " << (ba.is_open ? "Open" : "Closed") << endl;
        return (console);
    }

    friend ofstream &operator<<(ofstream &out_file, Bank_Account &ba)
    {
        out_file << ba.account_id << endl
                 << ba.owner_id << endl
                 << ba.available_funds << endl;
        out_file << ba.is_open << endl;
        return (out_file);
    }

    friend ifstream &operator>>(ifstream &in_file, Bank_Account &ba)
    {
        in_file >> ba.account_id;
        in_file >> ba.owner_id;
        in_file >> ba.available_funds;
        in_file >> ba.is_open;
        return (in_file);
    }
};

#endif /* BANK_ACCOUNT_CPP_ */