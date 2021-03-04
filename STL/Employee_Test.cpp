#include "Employee_Vector.cpp"
#include <vector>

int main()
{
    cout << "Employee Vector Test" << endl;
    
    // TC(1): Declare a product
    Product p1("Destiny", 10.0, 10);
    cout << p1;

    // TC(2): Write and read the product
    string employee_fname;
    cout << "Enter a filename: ";
    cin >> employee_fname;

    ofstream out_file(employee_fname);
    if (!out_file.is_open()) {
        cout << "ERROR: Unable to open file for writing: " << employee_fname << endl;
    }

    out_file << p1;
    out_file.close();

    // TC(3): Read a product
    Product *p2 = new Product();
    ifstream in_file(employee_fname);
    if (!in_file.is_open()) 
    {
        cout << "ERROR: Unable to open for reading: " << employee_fname << endl;
    }

    in_file >> *p2;
    cout << "Read in product:" << *p2 << endl;
    delete p2;
    in_file.close();

    // Write one item from the vector
    vector<Product> v1;
    Product v_prod1("Destiny", 20.0, 200);
    v1.push_back(v_prod1);

    vector<Product>::iterator itr;
    for (itr = v1.begin(); itr != v1.end(); itr++)
    {
        cout << *itr;
    }

}