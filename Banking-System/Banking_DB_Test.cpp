#ifndef BANKING_DB_TEST_CPP_
#define BANKING_DB_TEST_CPP_

#include "Banking_DB.cpp"

int main()
{
    // TC(1): Open a blank db
    vector<Bank_Account> test_accounts_vct;    
    test_accounts_vct.push_back(Bank_Account(1, 1, 100.50, true));
    Banking_DB test_db1("./Test-DB/empty-accounts-file.txt", &test_accounts_vct);
    test_db1.initialize();
    cout << test_db1;

    // TC(2): Open a pre-initialized db
    vector<Bank_Account> empty_accounts_vct;
    Banking_DB test_db2("./Test-DB/test-accounts-file.txt", &empty_accounts_vct);
    test_db2.initialize();
    cout << test_db2;

    // TC(3): Write a update to the db

    // TC(4): Read updated db

}
#endif /* BANKING_DB_TEST_CPP_ */