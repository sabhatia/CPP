#include <iostream>
#include <string>

using namespace std;

int main()
{
    string base_str, height_str;
    float base, height = 0.0;
    float area = 0.0;

    cout << "Enter the base of triangle: ";
    getline(cin, base_str);
    cout << "Enter the height of the triangle: ";
    getline(cin, height_str);

    base = stof(base_str); height = stof(height_str);
    area = (base * height)/2;
    cout << "Area is: " << area << "\n";
}