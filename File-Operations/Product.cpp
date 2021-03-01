#include "Product.h"

Product::Product (u_int id, string name, u_int quantity)
{
    this->id = id;
    this->name = name;
    this->quantity = quantity;
}

u_int Product::get_id ()
{
    return (this->id);
}

string Product::get_name ()
{
    return (this->name);
}

u_int Product::get_quantity ()
{
    return (this->quantity);
}

ostream& operator<< (ostream& console, Product& product_info)
{
    console << "Product Name: " << product_info.name << endl;
    console << "\tID: " << product_info.id << endl;
    console << "\tQuantity: " << product_info.quantity << endl;
    return (console);
} 

ofstream& operator<< (ofstream& out_file, Product &product_info)
{
    out_file << product_info.id << endl << product_info.name << endl << product_info.quantity << endl;
    return (out_file);
}

ifstream& operator>> (ifstream& in_file, Product &product_info)
{
    in_file >> product_info.id;
    in_file >> product_info.name;
    in_file >> product_info.quantity;
    return (in_file);
}