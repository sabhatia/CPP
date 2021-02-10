#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        const uint TOTAL_SUBJECTS = 3;
        uint    roll_number;
        string  name;
        uint*   marks;
    public:
        Student(uint s_roll, string s_name, uint *s_marks);
        uint* get_transcript(void);
        uint  get_total_marks(void);
        uint  get_total_subjects(void);
        char  get_grade(void);

        friend ostream& operator<<(ostream& out, Student &s1);
};

Student::Student(uint s_roll, string s_name, uint* s_marks)
{
    // deep copy - specially the marks
    this->roll_number = s_roll;
    this->name = s_name;
    this->marks = new uint[this->TOTAL_SUBJECTS];
    memcpy(this->marks, s_marks, sizeof(uint) * this->TOTAL_SUBJECTS);
}

uint* Student::get_transcript (void)
{
    // Allocate memory for return
    uint* marks_list = new uint[this->TOTAL_SUBJECTS];
    if (marks_list == nullptr) 
    {
        return nullptr;
    }
    memcpy(marks_list, this->marks, sizeof(uint) * this->TOTAL_SUBJECTS);
    return marks_list;
}
uint Student::get_total_subjects (void)
{
    return this->TOTAL_SUBJECTS;
}

uint Student::get_total_marks (void)
{
    int total_marks = 0;
    for (int indx = 0; indx < this->TOTAL_SUBJECTS; indx++)
    {
        total_marks += this->marks[indx];
    }
    return (total_marks);
}

char Student::get_grade(void)
{
    const uint MIN_B_GRADE = 60;
    const uint MIN_A_GRADE = 80;
    
    float avg_score = this->get_total_marks()/this->TOTAL_SUBJECTS;
    if (avg_score < MIN_B_GRADE) 
    {
        return 'C';
    } 
    else if (avg_score < MIN_A_GRADE)
    {
        return 'B';
    } 
    else
    {
        return 'A';
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
    cout << "--------------" << endl;
    return cout;
}

int main()
{
    uint s1_marks[] = {60,70,80};
    string s1_name = "Sandeep";
    Student *s1 = new Student(1, s1_name, s1_marks);

    // Print the student record
    cout << *s1;

    // Print the marks individually
    uint *marks_list = s1->get_transcript();
    cout << endl << "Student Marks" << endl;
    cout << "--------------" << endl;
    for (int indx = 0; indx < s1->get_total_subjects(); indx++)
    {
        cout << "Subject[" << indx << "]: " << marks_list[indx] << endl;
    }

    // Print the total of all subjects
    cout << endl << "Total Marks: " << s1->get_total_marks() << endl;

    // Print the grade
    cout << endl << "Student Grade: " << s1->get_grade() << endl;

    // Free any memory used
    delete(marks_list);
    delete(s1);
}
