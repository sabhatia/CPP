#include <gtest/gtest.h>
#include "../Banking_DB/Banking_DB.cpp"

TEST(GTBankingDB, DBInitEmpty)
{
    string empty_file = "/Users/sabhatia/Development/C++/Banking-System-II/Test-DB/empty-accounts-file.txt";
    vector<Bank_Account> ba_vct1;
    Bank_Account ba1(1, 1, 1000.00, true);
    ba_vct1.push_back(ba1);

    Banking_DB ba_db1(empty_file, &ba_vct1);
    ba_db1.initialize();

    Bank_Account ba1_cpy = ba_db1.find_account(ba1.get_account_id());

    EXPECT_EQ(ba1_cpy.get_account_id(), ba1.get_account_id());
    EXPECT_EQ(ba1_cpy.get_funds(), ba1.get_funds());
    EXPECT_EQ(1, ba_vct1.size());
}

TEST(GTBankingDB, DBInitAccounts)
{
    string accounts_file = "/Users/sabhatia/Development/C++/Banking-System-II/Test-DB/test-accounts-file.txt";
    struct ba_data
    {
        int id;
        float amt;
    };

    ba_data ba_accts2_data[] = {{1, 1000.51}, {30303, 345678.51}};    

    vector<Bank_Account> ba_vct2;
    Banking_DB ba_db2(accounts_file, &ba_vct2);
    ba_db2.initialize();
    
    // DB ==> Vector should have 3 accounts
    EXPECT_EQ(3, ba_vct2.size());

    // Find accounts 1 and 30303
    Bank_Account ba2_cpy;
    ba2_cpy = ba_db2.find_account(ba_accts2_data[0].id);
    EXPECT_EQ(ba_accts2_data[0].id, ba2_cpy.get_account_id());
    EXPECT_EQ(ba_accts2_data[0].amt, ba2_cpy.get_funds());

    ba2_cpy = ba_db2.find_account(ba_accts2_data[1].id);
    EXPECT_EQ(ba_accts2_data[1].id, ba2_cpy.get_account_id());
    EXPECT_EQ(ba_accts2_data[1].amt, ba2_cpy.get_funds());
}