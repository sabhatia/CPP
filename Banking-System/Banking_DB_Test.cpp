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
    cout << user_account;
    if (user_account.get_account_id() == Banking_DB::NOT_FOUND_ACCOUNT_ID)
    {
        cout << "Test(5): Failed" << endl;
    }
    else{
        cout << "Test(5): Passed" << endl;
    }
    
    // TC(6): Add a duplicate account
    cout << "Test(6): Start" << endl;
    cout << "Test(6): Add duplicate account" << endl;
    float available_funds = test3_account.get_funds();

    Bank_Account duplicate_account = test_db4.create_new_account(5, 1000, 2000.00);
    cout << duplicate_account;
    if (duplicate_account.get_funds() != test3_account.get_funds())
    {
        cout << "Test(6): Failed" << endl;
    }
    else
    {
        cout << "Test(6): Passed" << endl;
    }

    // TC(7): Create account with less than minimum balance
    cout << "Test(7): Start" << endl;
    cout << "Test(7): Create less than minimum balance" << endl;

    Bank_Account min_account = test_db4.create_new_account(6, 1000, 400.00);
    cout << min_account;
    if (min_account.get_account_id() != Banking_DB::NOT_FOUND_ACCOUNT_ID)
    {
        cout << "Test(7): Failed" << endl;
    }
    else
    {
        cout << "Test(7): Passed" << endl;
    }

    // TC(10): Add funds to the account
    cout << "TC(10): Start\n";
    cout << "TC(10): Add funds to account\n";
    bool tx_success = test_db4.deposit_money_to_account(5, 500.0);
    cout << test_db4.find_account(5);
    if (tx_success)
    {
        cout << "TC(10): Passed\n";
    }
    else{
        cout << "TC(10): Failed\n";
    }
    
    // TC(11): Withdraw funds from account
    cout << "TC(11): Start\n";
    cout << "TC(11): Remove funds from account\n";
    tx_success = test_db4.withdraw_money_from_account(5, 567.0);
    cout << test_db4.find_account(5);
    if (tx_success)
    {
        cout << "TC(11): Passed\n";
    }
    else{
        cout << "TC(11): Failed\n";
    }

    // TC(12): Lower funds to less that 500
    cout << "TC(12): Start\n";
    cout << "TC(12): Remove funds from account\n";
    tx_success = test_db4.withdraw_money_from_account(5, 200.0); // expected to fail
    cout << test_db4.find_account(5);
    if (!tx_success)
    {
        cout << "TC(12): Passed\n";
    }
    else{
        cout << "TC(12): Failed\n";
    }
    
    // TC(8): Close the new account
    cout << "Test(8): Start" << endl;
    cout << "Test(8): Close account" << endl;
    float account5_amt = (test_db4.find_account(5)).get_funds();
    float closing_amt = test_db4.close_existing_account(5);
    Bank_Account closed_acct = test_db4.find_account(5);

    cout << closed_acct;
    cout << "Account had " << closing_amt << " in final funds." << endl;

    if (closing_amt != account5_amt) 
    {
        cout << "Expected:" << account5_amt << " Actual: " << closing_amt << endl;
        cout << "Test(8): Failed" << endl;
    }
    else
    {
        cout << "Test(8): Passed" << endl;
    }

    // TC(9: All closed accounts
    cout << "Test(9): Start\n";
    cout << "Test(9): List Closed accounts\n";
    test_db4.list_closed_accounts();
    cout << "Test(9): Passed\n";
}
#endif /* BANKING_DB_TEST_CPP_ */