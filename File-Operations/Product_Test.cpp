#include "Product.h"

int main()
{
    // TC(1): Test product allocation
    cout << "TC1: Allocate and print a Product" << endl;
    Product p1(1, "Destiny", 10);
    cout << p1 << endl;

    // TC(2): Test multiple product allocation
    u_int total_products;
    string product_name;
    u_int  product_id;
    u_int  product_quantity;
    
    // Get how many products we need
    cout << "TC2: Dynamically Allocate Products" << endl;
    cout << "Enter total products: ";
    cin >> total_products;

    // Determine how many products user wants to track
    typedef Product* Product_Ptr;
    Product_Ptr* products = new Product_Ptr[total_products];
    
    if (!products) 
    {
        cout << "ERROR: No memory for product tracking. Exiting..." << endl;
        return (1);
    }
    
    // Get product details
    for (int indx = 0; indx < total_products; indx++)
    {
        cout << "Gathering info for Product #" << indx+1 << endl;
        cout << "Product Name: "; cin >> product_name;
        cout << "Product ID: "; cin >> product_id;
        cout << "Product Quantity: "; cin >> product_quantity;

        products[indx] = new Product(product_id, product_name, product_quantity);
    }

    cout << "Product Catalogue" << endl << endl;
    for (int indx = 0; indx < total_products; indx++)
    {
        cout << *products[indx];
    }
    cout << endl;

    // TC(3): Write to a file
    cout << "TC3: Write products to a file" << endl;

    ofstream out_file;
    string products_filename;

    cout << "Enter name of file to write: "; cin >> products_filename;
    out_file.open(products_filename);
    if (!out_file.is_open())
    {
        cout << "ERROR: TC3: Could not open file '" << products_filename << "'" << endl;
        return (1);
    }
    for (int indx = 0; indx < total_products; indx++)
    {
        out_file << *products[indx];
    }
    out_file.close();

    // TC(4): Read from a file
    cout << "TC4: Read products from a file" << endl;

    ifstream in_file;
    in_file.open(products_filename);
    if (!in_file.is_open())
    {
        cout << "ERROR: TC4: Could not open file '" << products_filename << "'" << endl;
    }

    Product_Ptr *in_products = new Product_Ptr[total_products];
    cout << "Processing produts from file: " << products_filename << endl;
    for (int indx = 0; indx < total_products; indx++)
    {
        in_products[indx] = new Product();
        in_file >> *in_products[indx];
        cout << *in_products[indx];
    }
    in_file.close();

    // Free allocated memory
    for (int indx = 0; indx < total_products; indx++)
    {
        delete in_products[indx];
        delete products[indx];
    }

    delete [] in_products;
    delete [] products;
}