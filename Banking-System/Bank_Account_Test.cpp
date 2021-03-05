#include "Bank_Account.cpp"

int Bank_Account_Tests()
{
    // TC(1): Create Bank Account class and print
    Bank_Account check1(1, 1, 1000.00, true);
    cout << check1 << endl;
    cout << "TC(1): Passed" << endl;

    // TC(2): Write to file
    string acct_fname = "accounts_data.txt";
    ofstream out_file(acct_fname);
    try
    {
        if (!out_file.is_open())
        {
            throw("TC(2): ERROR: Could not open file " + acct_fname + " for writing.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "TC(2): Failed" << endl;
    }
    out_file << check1;
    cout << "TC(2): Passed" << endl;

    // TC(3): Read from file
    Bank_Account check3;
    ifstream in_file(acct_fname);
    try
    {
        if (!in_file.is_open())
        {
            throw("TC(3): ERROR: Coult not open file " + acct_fname + "for reading.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "TC(3): Failed" << endl;
    }

    in_file >> check3;
    cout << check3;
    cout << "TC(3): Passed" << endl;
}