#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        const uint TOTAL_SUBJECTS = 3;
        uint roll_number;
        string name;
        uint marks[3];
    public:
        Student(uint s_roll, string s_name, uint *s_marks);
        bool get_transcript(uint *marks_buf);
        uint  get_total_marks();
        char  get_grade();
        void  display_details();
        friend ostream& operator<<(ostream& out, Student &s1);
};

Student::Student(uint s_roll, string s_name, uint* s_marks)
{
    this->roll_number = s_roll;
    this->name = s_name;
    memcpy(this->marks, s_marks, sizeof(this->marks));
}

bool Student::get_transcript (uint* marks_buf)
{
    return true;
}

uint Student::get_total_marks(void)
{
    return 0;
}

char Student::get_grade(void)
{
    return ('Z');
}

void Student::display_details(void)
{
    cout << "Student Record" << endl;
    cout << "--------------" << endl;
    cout << "Name: " << this->name << endl;
    cout << "Roll #: " << this->roll_number << endl;
    cout << "Marks:" << endl;
    for (int indx = 0; indx < this->TOTAL_SUBJECTS; indx++)
    {
        cout << "\tSubject[" << indx+1 << "]: " << this->marks[indx] << endl;
    }
}

ostream& operator<< (ostream& cout, Student &s1)
{
    cout << "Student Record" << endl;
    cout << "--------------" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll #: " << s1.roll_number << endl;
    cout << "Marks:" << endl;
    for (int indx = 0; indx < s1.TOTAL_SUBJECTS; indx++)
    {
        cout << "\tSubject[" << indx+1 << "]: " << s1.marks[indx] << endl;
    }
    return cout;
}

int main()
{
    uint s1_marks[] = {70,80,90};
    string s1_name = "Sandeep";
    Student *s1 = new Student(1, s1_name, s1_marks);
    s1->display_details();
    cout << *s1;
    delete(s1);
}