#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
    string id;
    string name;
    int score;
};

template <class T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b)
{
    return (a < b) ? a : b;
}

void addStudent(vector<Student>& students)
{
    Student s;

    cout << "Enter ID: ";
    cin >> s.id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == s.id)
        {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Score: ";
    cin >> s.score;

    students.push_back(s);

    cout << "Student added successfully!\n";
}

void listStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data.\n";
        return;
    }

    cout << "\n---------------------------------\n";
    cout << left
         << setw(12) << "ID"
         << setw(12) << "Name"
         << setw(8) << "Score" << endl;
    cout << "---------------------------------\n";

    for (int i = 0; i < students.size(); i++)
    {
        cout << left
             << setw(12) << students[i].id
             << setw(12) << students[i].name
             << setw(8) << students[i].score
             << endl;
    }
}

void sortStudents(vector<Student>& students)
{
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b)
         {
             return a.score > b.score;
         });

    cout << "Sorted successfully!\n";
}

void searchStudent(const vector<Student>& students)
{
    string id;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "\nStudent Found\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Score: " << students[i].score << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void showStatistics(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data.\n";
        return;
    }

    int highest = students[0].score;
    int lowest = students[0].score;
    int sum = 0;
    int pass = 0;
    int fail = 0;

    for (int i = 0; i < students.size(); i++)
    {
        sum += students[i].score;

        highest = getMax(highest, students[i].score);
        lowest = getMin(lowest, students[i].score);

        if (students[i].score >= 60)
            pass++;
        else
            fail++;
    }

    double average = (double)sum / students.size();

    cout << fixed << setprecision(2);

    cout << "\n===== Statistics =====\n";
    cout << "Average Score : " << average << endl;
    cout << "Highest Score : " << highest << endl;
    cout << "Lowest Score  : " << lowest << endl;
    cout << "Pass Students : " << pass << endl;
    cout << "Fail Students : " << fail << endl;
}

int main()
{
    vector<Student> students;
    int choice;

    do
    {
        cout << "\n===== Student Grade Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. List All Students\n";
        cout << "3. Sort By Score\n";
        cout << "4. Search By ID\n";
        cout << "5. Show Statistics\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            listStudents(students);
            break;

        case 3:
            sortStudents(students);
            break;

        case 4:
            searchStudent(students);
            break;

        case 5:
            showStatistics(students);
            break;

        case 0:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}