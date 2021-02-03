#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    double radius = 0.0;
    cout.precision(10);

    cout << "Enter the RADIUS of the Circle: ";
    cin >> radius;
    cout << "Area of a circle with RADIUS: " << radius << " is : " << (double)(M_PI * radius * radius) << endl;
} 