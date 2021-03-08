#ifndef BANKING_DB_CPP_
#define BANKING_DB_CPP_

#include <string>
#include <fstream>
#include <vector>
#include <cassert>
#include "Bank_Account.cpp"

using namespace std;

class Banking_DB
{
private:
    string data_source_name;
    ifstream in_file;
    ofstream out_file;
    vector<Bank_Account> *accounts_vct; // make this shared ptr later
public:
    static const u_int NOT_FOUND_ACCOUNT_ID = 0;

    Banking_DB(string data_source, vector<Bank_Account> *ba_vct)
    {
        this->data_source_name = data_source;
        assert(ba_vct != nullptr);
        this->accounts_vct = ba_vct; // validate for null pointer
    }

    // Read the contents from the DB source
    void initialize()
    {
        cout << "Initializing DB..." << endl;
        in_file.open(this->data_source_name);
        if (!in_file.is_open())
        {
            throw("Couldn't open file " + this->data_source_name + " for I/O");
        }
        assert(in_file.is_open());

        // Read from the file
        Bank_Account tmp_acct;
        while (true)
        {
            in_file >> tmp_acct;
            if (in_file.eof())
            {
                break;
            }
            accounts_vct->push_back(tmp_acct);
        }
        cout << "Loaded in " << this->accounts_vct->size() << " entries." << endl;
    }

    // Write the contents to the db destination
    void flush()
    {
        cout << "Flushing to DB..." << endl;
        out_file.open(this->data_source_name);
        if (!out_file.is_open())
        {
            throw("Couldn't open file " + this->data_source_name + " for I/O");
        }
        assert(out_file.is_open());

        // Write to the file
        for (vector<Bank_Account>::iterator itr = this->accounts_vct->begin();
             itr != this->accounts_vct->end(); itr++)
        {
            out_file << *itr;
        }
        cout << "Flushed out " << this->accounts_vct->size() << " entries." << endl;
    }

    Bank_Account find_account(u_int user_account_id)
    {
        Bank_Account dummy_act(0,0,0,false);

        for (auto user_account : *this->accounts_vct)
        {
            if (user_account.get_account_id() == user_account_id)
            { 
                return (user_account);
            }
        }

        // didn't find any account. Return a dummy.
        return (dummy_act);
    }

    Bank_Account create_new_account(u_int account_id, u_int owner_id, float starting_amt)
    {
        Bank_Account existing_account = find_account(account_id);
        Bank_Account dummy_account(0, 0, 0, false);

        // Check the account id doesn't already exist
        if (existing_account.get_account_id() != NOT_FOUND_ACCOUNT_ID)
        {
            cout << "ERROR: Account " << account_id << " already exists. None created.\n";
            return (existing_account);
        }

        // Fix to better validate
        if (starting_amt < Bank_Account::MINIMUM_BALANCE)
        {
            cout << "ERROR: Minimum balance of " << Bank_Account::MINIMUM_BALANCE
                 << " required when opening an account.\n";
            return (existing_account);
        }

        // Validations passed. Create the account
        Bank_Account new_account(account_id, owner_id, starting_amt, true);
        this->accounts_vct->push_back(new_account);
        this->flush();
        return (new_account);
    }

    float close_existing_account(u_int account_id)
    {
        Bank_Account dummy_account(0, 0, 0, false);
        Bank_Account existing_account;
        // Check if the account exists
        existing_account = find_account(account_id);
        if (existing_account.get_account_id() == NOT_FOUND_ACCOUNT_ID)
        {
            cout << "ERROR: Account[" << account_id << "] doesn't exist.\n";
            return (0.0);
        }

        // Check that it is open
        if (existing_account.is_open_account() != true)
        {
            cout << "ERROR: Account[" << account_id << "] already closed.\n";
            return (0.0);
        }

        // Close the account. Withdraw funds to user
        existing_account.close_account();
        float remove_funds = existing_account.get_funds();
        existing_account.withdraw_funds(remove_funds);
        this->flush();
        return (remove_funds);

    }

    void list_open_accounts()
    {
        vector<Bank_Account>::iterator open_itr;
        for (open_itr = this->accounts_vct->begin();
             open_itr != this->accounts_vct->end();
             open_itr++)
        {
            if (open_itr->is_open_account())
            {
                cout << *open_itr;
            }
        }
    }

    void list_closed_accounts()
    {
        vector<Bank_Account>::iterator close_itr;
        for (close_itr = this->accounts_vct->begin();
             close_itr != this->accounts_vct->end();
             close_itr++)
        {
            if (!close_itr->is_open_account())
            {
                cout << *close_itr;
            }
        }        
    }

    friend ostream &operator<<(ostream &console, Banking_DB &db_info)
    {
        console << "Bank DB Details:" << endl;
        console << "\tSource: " << db_info.data_source_name << endl;
        console << "\tConnection: " << (db_info.in_file.is_open() ? "Open" : "Closed") << endl;
        console << "\tAccount Details(" << db_info.accounts_vct->size() << ") accounts: " << endl;
        for (vector<Bank_Account>::iterator itr = db_info.accounts_vct->begin();
             itr != db_info.accounts_vct->end(); itr++)
        {
            console << *itr;
        }

        return (console);
    }
};
#endif /* BANKING_DB_CPP_ */