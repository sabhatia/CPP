#include "Banking_System.cpp"

int main()
{
    BANKING_OPTIONS banking_option = SB_OPTION_NONE;

    // Initialize the Banking system
    Banking_System sandeep_bank("Sandeep Bank", "/Users/sabhatia/Development/C++/Banking-System-II/Test-DB/sandeep-bank.txt");
    // Print the starting banner and options
    while (true)
    {
        /* Bank processing loop */
        Banking_System::print_banking_banner();
        Banking_System::print_banking_menu();
        banking_option = Banking_System::get_banking_option();
        if (banking_option == SB_OPTION_QUIT_BANKING)
        {
            break;
        }
        sandeep_bank.process_option(banking_option);
    }

    cout << "Thank you for banking with " << sandeep_bank.get_name() << endl;
} 