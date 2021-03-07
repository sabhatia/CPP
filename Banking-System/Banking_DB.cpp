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