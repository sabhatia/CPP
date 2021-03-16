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

TEST(GTBankingDB, DBInitNotEmpty)
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

class GTBankingAccounts:public::testing::Test
{
protected:
    string tmp_filename = "/tmp/test-accounts-write-file.txt";
    vector<Bank_Account> ba_vct3;
    Banking_DB *bdb3;

    struct BA_details
    {
        int acct_id;
        int owner_id;
        float amt;
    };

    BA_details ba_new = {5, 50, 567.89};

    virtual void SetUp() override 
    {
        bdb3 = new Banking_DB(tmp_filename, &ba_vct3);
    }

    virtual void TearDown() override
    {
        delete bdb3;
    }
};

TEST_F(GTBankingAccounts, DBAccountAddFind)
{

    int orig_accts = ba_vct3.size();
    bdb3->create_new_account(ba_new.acct_id, ba_new.owner_id, ba_new.amt);
    EXPECT_EQ(orig_accts + 1, ba_vct3.size());

    Bank_Account ba_add = bdb3->find_account(ba_new.acct_id);
    EXPECT_EQ(ba_new.acct_id, ba_add.get_account_id());
    EXPECT_EQ(ba_new.amt, ba_add.get_funds());
}

TEST_F(GTBankingAccounts, DBAccountDuplicate)
{
    int orig_accts = ba_vct3.size();
    bdb3->create_new_account(ba_new.acct_id, ba_new.owner_id, ba_new.amt);
    EXPECT_EQ(orig_accts + 1, ba_vct3.size());

    // Try adding the same account
    bdb3->create_new_account(ba_new.acct_id, ba_new.owner_id, ba_new.amt);
    EXPECT_EQ(orig_accts + 1, ba_vct3.size());
}

TEST_F(GTBankingAccounts, DBAccountClose)
{
    int orig_accts = ba_vct3.size();
    bdb3->create_new_account(ba_new.acct_id, ba_new.owner_id, ba_new.amt);
    EXPECT_EQ(orig_accts + 1, ba_vct3.size());

    bdb3->close_existing_account(ba_new.acct_id);
    Bank_Account ba_close = bdb3->find_account(ba_new.acct_id);
    EXPECT_EQ(false, ba_close.is_open_account());
}

TEST(GTBankingDB, DBAccountBalanceMin)
{
    EXPECT_TRUE(false);
}

TEST(GTBankingDB, DBAccountBalanceAdd)
{
    EXPECT_TRUE(false);
}

TEST(GTBankingDB, DBAccountBalanceRemove)
{
    EXPECT_TRUE(false);
}

