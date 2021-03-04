#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Product
{
    private:
        string name;
        float price;
        u_int quantity;
    public:
        Product(string name = "", float price=0.0, u_int quantity = 0)
        {
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }   

        string get_name()
        {
            return (this->name);
        }

        float get_price()
        {
            return (this->price);
        }

        u_int get_quantity ()
        {
            return (this->quantity);
        }

        friend ostream& operator<< (ostream& console, Product& product_info)
        {
            console << "Product Name: " << product_info.name << endl;
            console << "\tID: " << product_info.price << endl;
            console << "\tQuantity: " << product_info.quantity << endl;
            return (console);
        } 

        friend ofstream& operator<< (ofstream& out_file, Product &product_info)
        {
            out_file << product_info.price << endl << product_info.name << endl << product_info.quantity << endl;
            return (out_file);
        }

        friend ifstream& operator>> (ifstream& in_file, Product &product_info)
        {
            in_file >> product_info.price;
            in_file >> product_info.name;
            in_file >> product_info.quantity;
            return (in_file);
        }                                                                        
};