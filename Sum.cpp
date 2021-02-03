#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int A[] = {2, 4, 6, 8, 10};

    for (int indx = 0; indx < 5; indx++) 
    {
        sum += A[indx];
        cout << "Sum: " << sum << endl;
    }
} 