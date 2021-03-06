#include "Banking_System.cpp"

int main()
{
    u_int banking_option = 0;

    // Initialize the Ban

    // Print the starting banner and options
    Banking_System::print_banking_banner();
    Banking_System::print_banking_menu();
    banking_option = Banking_System::get_banking_option();
    cout << "Selected Option: " << banking_option << endl;

} 