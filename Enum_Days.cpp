#include <iostream>

using namespace std;

enum day {mon, tue, wed, thu, fri, sat, sun};

int main()
{
    day today;

    today = thu;

    cout << "The day is: " << today << endl;

}