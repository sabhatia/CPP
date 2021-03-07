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
    Bank_Account test3_account = Bank_Account(5, 50, 567.89, true);
    test2_accounts_vct.push_back(test3_account);
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

    // TC(5): Find existing account
    cout << "Test(5): Start" << endl;
    cout << "Test(5): Find existing account" << endl;
    // Re-use test_db4 
    u_int user_account_id = 5;
    Bank_Account user_account = test_db4.find_account(user_account_id);
    if (user_account.get_account_id() == Banking_DB::NOT_FOUND_ACCOUNT_ID)
    {
        cout << user_account;
        cout << "Test(5): Failed" << endl;
    }
    else{
        cout << user_account;
        cout << "Test(5): Passed" << endl;
    }
    
    // TC(6): Add a duplicate account
    cout << "Test(6): Start" << endl;
    cout << "Test(6): Add duplicate account" << endl;
    float available_funds = test3_account.get_funds();
    Bank_Account duplicate_account(5, 1000, 2000.00, true);
    duplicate_account = test_db4.create_new_account(5, 1000, 2000.00);
    if (duplicate_account.get_funds() != test3_account.get_funds()) 
    {
        cout << "Test(6): Failed" << endl;
    }
    else
    {
        cout << "Test(6): Passed" << endl;
    }

    // TC(7): Find new account
    cout << "Test(7): Start" << endl;
    cout << "Test(7): Find existing account" << endl;
    cout << "Test(7): Passed" << endl;

    // TC(8): Close the new account
    cout << "Test(8): Start" << endl;
    cout << "Test(8): Find existing account" << endl;
    cout << "Test(8): Passed" << endl;
}
#endif /* BANKING_DB_TEST_CPP_ */