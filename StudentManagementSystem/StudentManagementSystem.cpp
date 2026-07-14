#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
};

const string FILE_NAME = "students.txt";

vector<Student> loadStudents()
{
    vector<Student> students;
    ifstream file(FILE_NAME);

    Student s;
    while (file >> s.id >> s.name >> s.age)
    {
        students.push_back(s);
    }

    file.close();
    return students;
}

void saveStudents(vector<Student> students)
{
    ofstream file(FILE_NAME);

    for (int i = 0; i < students.size(); i++)
    {
        file << students[i].id << " "
            << students[i].name << " "
            << students[i].age << endl;
    }

    file.close();
}

void displayStudents(vector<Student> students)
{
    cout << "\nID\tName\tAge\n";
    cout << "-------------------------\n";

    if (students.empty())
    {
        cout << "No student records found.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].id << "\t"
            << students[i].name << "\t"
            << students[i].age << endl;
    }
}
void addStudent(vector<Student>& students)
{
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Student Age: ";
    cin >> s.age;

    students.push_back(s);
    saveStudents(students);

    cout << "\nStudent Added Successfully!\n";
}

void updateStudent(vector<Student>& students)
{
    int id;
    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "Enter New Name: ";
            cin >> students[i].name;

            cout << "Enter New Age: ";
            cin >> students[i].age;

            found = true;
            break;
        }
    }

    if (found)
    {
        saveStudents(students);
        cout << "\nStudent Updated Successfully!\n";
    }
    else
    {
        cout << "\nStudent Not Found!\n";
    }
}

void deleteStudent(vector<Student>& students)
{
    int id;
    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);
            found = true;
            break;
        }
    }

    if (found)
    {
        saveStudents(students);
        cout << "\nStudent Deleted Successfully!\n";
    }
    else
    {
        cout << "\nStudent Not Found!\n";
    }
}
int main()
{
    vector<Student> students = loadStudents();

    int choice;

    do
    {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            displayStudents(students);
            break;

        case 3:
            updateStudent(students);
            break;

        case 4:
            deleteStudent(students);
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
