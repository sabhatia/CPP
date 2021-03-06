#ifndef BANKING_DB_CPP_
#define BANKING_DB_CPP_

#include <string>
#include <fstream>

using namespace std;

class Banking_DB
{
private:
    string data_source_name;
    fstream data_file;
public:
    Banking_DB(string data_source)
    {
        this->data_source_name = data_source;
    }
};
#endif /* BANKING_DB_CPP_ */