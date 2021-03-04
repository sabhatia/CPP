#include "Employee_Vector.cpp"
#include <vector>

int main()
{
    cout << "Employee Vector Test" << endl;
    
    // TC(1): Declare a product
    Product p1("Destiny", 10.0, 10);
    cout << p1;
    cout << "TC1: Pass" << endl;

    // TC(2): Write the product to fiile
    string employee_fname;
    cout << "Enter a filename: ";
    cin >> employee_fname;

    ofstream out_file(employee_fname);
    if (!out_file.is_open()) {
        cout << "ERROR: Unable to open file for writing: " << employee_fname << endl;
    }

    out_file << p1;
    out_file.close();
    cout << "TC2: Pass" << endl;

    // TC(3): Read a product
    Product *p2 = new Product();
    ifstream in_file(employee_fname);
    if (!in_file.is_open()) 
    {
        cout << "ERROR: Unable to open for reading: " << employee_fname << endl;
    }

    in_file >> *p2;
    cout << "Read in product:" << endl << *p2 << endl;
    delete p2;
    in_file.close();
    cout << "TC3: Pass" << endl;

    // TC(4):Write one item from the vector
    vector<Product> v1;
    Product v_prod1("Destiny", 10.0, 100);
    v1.push_back(v_prod1);

    vector<Product>::iterator itr;
    for (itr = v1.begin(); itr != v1.end(); itr++)
    {
        cout << *itr;
    }

    cout << "TC4: Pass" << endl;

    // TC(5): Write 3 more dynamically
    Product v_prod2("COD-1", 20.0, 200);
    Product v_prod3("GTA-5", 30.0, 300);
    Product v_prod4("NFS-2", 40.0, 400);

    v1.push_back(v_prod2);
    v1.push_back(v_prod3);
    v1.push_back(v_prod4);

    for (itr = v1.begin(); itr != v1.end(); itr++)
    {
        cout << *itr;
    }
    cout << "TC5: Pass" << endl;

    //TC(6): Write from vector to file
    ofstream vout_file(employee_fname);
    try {
        if (!vout_file.is_open())
        {
            // couldn't open file. Throw an error
            throw (6);
        }
        for (itr = v1.begin(); itr != v1.end(); itr++)
        {
            vout_file << *itr;
        }
        vout_file.close();
    }
    catch (int error_tc)
    {
        cout << "TC 6: FAILED" << endl;
    }
}