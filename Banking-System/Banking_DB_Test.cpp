#ifndef BANKING_DB_TEST_CPP_
#define BANKING_DB_TEST_CPP_

#include "Banking_DB.cpp"

int main()
{
    // TC(1): Open a blank db
    cout << "Test(1): Start" << endl;
    vector<Bank_Account> test1_accounts_vct;    
    test1_accounts_vct.push_back(Bank_Account(1, 1, 100.50, true));
    Banking_DB test_db1("./Test-DB/empty-accounts-file.txt", &test1_accounts_vct);
    test_db1.initialize();
    cout << test_db1;
    cout << "Test(1): Passed" << endl;

    // TC(2): Open a pre-initialized db
    cout << "Test(2): Start" << endl;
    vector<Bank_Account> test2_accounts_vct;
    Banking_DB test_db2("./Test-DB/test-accounts-file.txt", &test2_accounts_vct);
    test_db2.initialize();
    cout << test_db2;
    cout << "Test(2): Passed" << endl;
    

    // TC(3): Write a update to the db
    // Re-use vector of accounts from Test(2)
    cout << "Test(3): Start" << endl;
    string tmp_file = "/tmp/test-accounts-write-file.txt";
    Banking_DB test_db3(tmp_file, &test2_accounts_vct);
    test2_accounts_vct.push_back(Bank_Account(5, 50, 567.89, true));
    cout << "Test(3): Added 1 additional account entry." << endl;
    test_db3.flush();
    int test3_total_accounts = test2_accounts_vct.size();
    cout << "Test(3): Passed" << endl;

    // TC(4): Read updated db
    cout << "Test(4): Start" << endl;
    vector<Bank_Account> test4_accounts_vct;
    Banking_DB test_db4(tmp_file, &test4_accounts_vct);
    test_db4.initialize();
    cout << test_db4;
    cout << "Test(4): Passed" << endl;
}
#endif /* BANKING_DB_TEST_CPP_ */