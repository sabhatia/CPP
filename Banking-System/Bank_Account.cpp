#include <iostream>
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
    Bank_Account(u_int account_id = 0, u_int owner_id = 0, float available_funds = 0.0, bool is_open = false)
    {
        this->account_id = account_id;
        this->owner_id = owner_id;
        this->available_funds = available_funds;
        this->is_open = is_open;
    }

    friend ostream& operator<< (ostream& console, Bank_Account ba)
    {
        console << "Account Details:" << endl;
        console << "\tID: " << ba.account_id << endl;
        console << "\tOwner: " << ba.owner_id << endl;
        console << "\tFunds:" << ba.available_funds << endl;
        console << "\tStatus: " << (ba.is_open? "Open" : "Closed") << endl;
        return (console);
    }
};