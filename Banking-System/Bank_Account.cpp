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
    Bank_Account(u_int account_id = 0, u_int owner_id = 0,
                 float available_funds = 0.0, bool is_open = false)
    {
        this->account_id = account_id;
        this->owner_id = owner_id;
        this->available_funds = available_funds;
        this->is_open = is_open;
    }

    float deposit_funds(float additional_funds)
    {
        if (!is_open)
        {
            // Can't deposit in closed accounts
            cout << "Account is closed. Deposit cancelled" << endl;
        }

        available_funds += additional_funds;
        return (available_funds);
    }

    float withdraw_funds(float removed_funds)
    {
        if (available_funds > removed_funds)
        {
            available_funds -= removed_funds;
        }

        return (available_funds);
    }

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