# Student Grade Management System

## Project Description
This project is a C++ Template extended learning assignment focused on STL (Standard Template Library) and basic data structures. The system manages student records and demonstrates the use of STL containers, algorithms, and template functions.

## Technologies Used
- C++17
- Struct
- Vector
- Sort Algorithm
- Template Functions

## Features
1. Add Student
2. List All Students
3. Sort Students by Score
4. Search Student by ID
5. Show Statistics
   - Average Score
   - Highest Score
   - Lowest Score
   - Number of Passing Students
   - Number of Failing Students

## Data Structure

```cpp
struct Student {
    string id;
    string name;
    int score;
};
```

The program uses `vector<Student>` to store student information and `sort()` to arrange records by score.

## Template Functions

```cpp
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}
```

These functions are used to determine the highest and lowest scores.

## Compilation

```bash
g++ -std=c++17 main.cpp -o main
```

## Execution

### Windows

```bash
main.exe
```

### Linux / macOS

```bash
./main
```

## Example Menu

```text
===== Student Grade Management System =====

1. Add Student
2. List All Students
3. Sort by Score
4. Search by ID
5. Show Statistics
0. Exit
```

## Learning Outcomes
- Understand the relationship between Templates and STL.
- Learn how to use STL containers such as vector.
- Practice sorting and searching techniques.
- Apply template functions in a real project.
- Improve C++ programming skills through a practical application.