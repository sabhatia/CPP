#include <vector>
#include "Product.cpp"

int main()
{
    cout << "Employee Vector Test" << endl;

    // TC(1): Declare a product
    Product p1("Destiny", 10.0, 10);
    cout << p1;
    cout << "TC(1): Passed" << endl;

    // TC(2): Write the product to fiile
    string employee_fname = "prod_inventory";
    //cout << "Enter a filename: ";
    //cin >> employee_fname;

    ofstream out_file(employee_fname);
    if (!out_file.is_open()) {
        cout << "ERROR: Unable to open file for writing: " << employee_fname << endl;
    }

    out_file << p1;
    out_file.close();
    cout << "TC(2): Passed" << endl;

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
    cout << "TC(3): Passed" << endl;

    // TC(4):Write one item from the vector
    vector<Product> v_write;
    Product v_prod1("Destiny", 10.0, 100);
    v_write.push_back(v_prod1);

    vector<Product>::iterator itr;
    for (itr = v_write.begin(); itr != v_write.end(); itr++)
    {
        cout << *itr;
    }

    cout << "TC(4): Passed" << endl;

    // TC(5): Write 3 more dynamically
    Product v_prod2("COD-1", 20.0, 200);
    Product v_prod3("GTA-5", 30.0, 300);
    Product v_prod4("NFS-2", 40.0, 400);

    v_write.push_back(v_prod2);
    v_write.push_back(v_prod3);
    v_write.push_back(v_prod4);

    for (itr = v_write.begin(); itr != v_write.end(); itr++)
    {
        cout << *itr;
    }
    cout << "TC(5): Passed" << endl;

    // TC(6): Write from vector to file
    ofstream vout_file(employee_fname);
    try 
    {
        if (!vout_file.is_open())
        {
            // couldn't open file. Throw an error
            throw (6);
        }
        for (itr = v_write.begin(); itr != v_write.end(); itr++)
        {
            vout_file << *itr;
        }
        vout_file.close();

        cout << "TC(6): Passed" << endl;
    }
    catch (int error_tc)
    {
        cout << "TC(6): Failed" << endl;
    }

    // TC(7): Read from file to vector
    ifstream vin_file(employee_fname);
    vector <Product> v_read;
    Product prod_ptr;
    try
    {
        cout << "TC(7): Opening file for reading: " << employee_fname << endl;
        if (!vin_file.is_open())
        {
            throw(7);
        }
        int entry_count = 0;
        while (true)
        {
            vin_file >> prod_ptr;
            if (vin_file.eof())
            {
                break;
            }
            entry_count++;
            v_read.push_back(prod_ptr);
        }
        cout << "TC(7): Read in " << entry_count << " entries." << endl;
        vout_file.close();
        cout << "TC(7): Passed" << endl;
    }
    catch (int error_tc)
    {
        cout << "TC(7): Failed" << endl;
    }

    // TC(8): Check if we got the correct entries
    int indx = 0;
    for (indx = 0, itr = v_read.begin(); itr != v_read.end(); itr++, indx++)
    {
        cout << "Entry[" << indx << "]" << endl << *itr;
    }
    if (v_read.size() == v_write.size())
    {
        cout << "TC(8): Passed" << endl;
    }
    else
    {
        cout << "TC(8): Expected(" << v_write.size() << "). Actual (" << v_read.size() << ")" << endl;
        cout << "TC(8): Failed" << endl;
    }
}