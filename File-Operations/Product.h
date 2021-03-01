#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Product
{
    private:
        u_int id;
        string name;
        u_int quantity;
    public:
        Product(u_int id = 0, string name = "", u_int quantity = 0);
        u_int get_id();
        string get_name();
        u_int get_quantity();

        // Friends
        friend ostream& operator<< (ostream& console, Product &product_info);
        friend ofstream& operator<< (ofstream& out_file, Product &product_info);
        friend ifstream& operator>> (ifstream& in_file, Product &product_info);
};