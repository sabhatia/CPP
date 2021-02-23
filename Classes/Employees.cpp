#include <iostream>
#include <string>

using namespace std;

class Employee
{
    private:
        uint employee_id;
        string employee_name;
    public:
        Employee(uint emp_id = 0, string name = "");
        uint get_employee_id();
        string get_employee_name();
        friend ostream& operator<< (ostream& console, Employee& emp);
};

class FullTimeEmployee: virtual public Employee
{
    private: 
        float employee_salary;
    public:
        FullTimeEmployee(uint emp_id = 0, string name = "", float salary = 0.0);
        float get_employee_salary();
        friend ostream& operator<< (ostream& console, FullTimeEmployee &f_emp);
};

class PartTimeEmployee: virtual public Employee
{
    private:
        float employee_hourly_rate;
    public:
        PartTimeEmployee(uint emp_id = 0, string name="", float hourly_rate = 0.0);
        float get_employee_rate();
        friend ostream& operator<< (ostream& console, PartTimeEmployee& p_emp);
};

Employee::Employee(uint emp_id, string name)
{
    this->employee_id = emp_id;
    this->employee_name = name;
}

uint Employee::get_employee_id()
{
    return (this->employee_id);
}

string Employee::get_employee_name()
{
    return (this->employee_name);
}

ostream& operator<< (ostream& console, Employee& emp)
{
    console << "Employee Details" << endl;
    console << "----------------" << endl;
    console << "\tID:" << emp.get_employee_id() << endl;
    console << "\tName: " << emp.get_employee_name() << endl;

    return (console);
}

FullTimeEmployee::FullTimeEmployee(uint emp_id, string name, float salary):Employee(emp_id, name)
{
    this->employee_salary = salary;
}

float FullTimeEmployee::get_employee_salary()
{
    return (this->employee_salary);
}

ostream& operator<< (ostream& console, FullTimeEmployee& f_emp)
{
    operator<<(console, (Employee&)f_emp); 
    console << "\tSalary: " << f_emp.get_employee_salary();
    return (console);
}

PartTimeEmployee::PartTimeEmployee(uint emp_id, string name, float hourly_rate):Employee(emp_id, name)
{
    this->employee_hourly_rate = hourly_rate;
}

float PartTimeEmployee::get_employee_rate()
{
    return (this->employee_hourly_rate);
}
ostream& operator<< (ostream& console, PartTimeEmployee& p_emp)
{
    operator<<(console, (Employee&)p_emp);
    console << "\tMonthly Rate: " << p_emp.get_employee_rate() * 160.0 << endl;
    return (console);
}

int main()
{
    FullTimeEmployee f1(1, "Sandeep Bhatia", 45000.0);
    PartTimeEmployee p1(2, "Ansh Bhatia", 500.0);

    //string emp_name = f1.get_employee_name();
    //cout << "Emp1: \n\tID: " << f1.get_employee_id() << "\n\tName: " << emp_name;
    //cout << "\n\tSalary: " << f1.get_employee_salary() << endl;
    cout << f1 << "\n" << endl; 
    cout << p1 << "\n" << endl;
    //cout << "Emp2: " << p1.get_employee_id() << endl;
}