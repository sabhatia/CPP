#include <iostream>
#include <string>

using namespace std;

class Complex
{
    private:
        float real;
        float imaginary;
    public:
        Complex (float real=0, float imaginary = 0);
        Complex (Complex& c1);
        Complex operator+ (Complex rhs);
        friend ostream& operator<< (ostream& cout, Complex &c1);
};

Complex::Complex (float real, float imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

Complex::Complex (Complex &c1)
{
    this->real = c1.real;
    this->imaginary = c1.imaginary;
}

Complex Complex::operator+ (Complex rhs)
{
    Complex c_add;

    c_add.real = real + rhs.real;
    c_add.imaginary = imaginary + rhs.imaginary;

    return (c_add);
}

ostream& operator<< (ostream &out_pipe, Complex& c1)
{
    out_pipe << "(" << c1.real << ", " << c1.imaginary << "i) ";
    return out_pipe;
}

int main()
{
    Complex c1;
    Complex c2(5,2);
    Complex c3(7,4);

    cout << "Complex numbers" << endl;

    cout << "C1: " << c1 << "C2: " << c2 << "C3: " << c3 << endl;

    Complex c4, c5; 
    c4 = c1 + c2;
    c5 = c2 + c3;

    cout << "C1 + C2: " << c4 << endl;
    cout << "C2 + C3: " << c5 << endl;
}