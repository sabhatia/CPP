#ifndef BANKING_DB_TEST_CPP_
#define BANKING_DB_TEST_CPP_

#include "Banking_DB.cpp"

int main()
{
    vector<Bank_Account> test_accounts_vct;    
    Banking_DB file_db("./Test-DB/Test-file.txt", &test_accounts_vct);
    cout << file_db;
}
#endif /* BANKING_DB_TEST_CPP_ */