#include <gtest/gtest.h>
#include "../Banking_DB/Bank_Account.cpp"

TEST(GTBankAccount, BASetup)
{
    Bank_Account ba1(1, 1, 1000.00, true);
    EXPECT_EQ(1, ba1.get_account_id());
    EXPECT_EQ(1, ba1.get_owner_id());
    EXPECT_EQ(1000.00, ba1.get_funds());
    EXPECT_EQ(true, ba1.is_open_account());
}

TEST(GTBankAccount, BAStoreRetrive)
{
    Bank_Account ba2(1,1,1000.00, true);
    string ba_file = "accounts_data.txt";
    ofstream out_file(ba_file);
    out_file << ba2;
    out_file.close();

    ifstream in_file(ba_file);
    Bank_Account ba3;
    in_file >> ba3;

    EXPECT_EQ(ba2.get_account_id(), ba3.get_account_id());
    EXPECT_EQ(ba2.get_owner_id(), ba3.get_owner_id());
    EXPECT_EQ(ba2.get_funds(), ba3.get_funds());
    EXPECT_EQ(ba2.is_open_account(), ba3.is_open_account());
}

TEST(GTBankAccount, BADeposit)
{
    float origin_amt  = 4000.00;
    float deposit_amt = 44.78;
    Bank_Account ba4(4, 40, origin_amt, true);
    ba4.deposit_funds(deposit_amt);

    EXPECT_EQ(origin_amt + deposit_amt, ba4.get_funds());
}

TEST(GTBankAccount, BAWithdraw)
{
    float origin_amt = 4567.89;
    float remove_amt =  567.89;
    Bank_Account ba5(5, 50, origin_amt, true);
    ba5.withdraw_funds(remove_amt);
    
    EXPECT_EQ(origin_amt - remove_amt, ba5.get_funds());
}