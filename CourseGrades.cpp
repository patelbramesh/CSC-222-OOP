/*
File Name: CourseGrades.cpp
Author: Bramesh Patel
Date: 10/07/2025

Description:
This program reads student data from a file where the first line indicates
the number of students and number of test scores. Each following line contains
a student's name, ID, and test scores. The program dynamically allocates an
array of structs to store the student data, calculates each student’s average
test score and letter grade, prints a formatted report, and properly releases
all allocated memory before it ends.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
Struct: student
Holds all data related to a student including:
- name
- ID
- dynamic array for test scores
- computed average
- letter grade
*/
struct student
{
    string name;
    int id;
    double *scores;
    double average;
    char grade;
};

/*
Function: findGrade
Input: average test score (double)
Precondition: average must be between 0 and 100.
Postcondition: Returns the letter grade based on standard grading scale.
*/
char findGrade(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

/*
Function: getData
Input: open file reference, number of students (by reference), number of tests (by reference)
Precondition: File must exist and follow the given format.
Postcondition: Reads all student records from the file, dynamically allocates
arrays for test scores, and returns a pointer to the array of structs.
*/
student* getData(ifstream &file, int &studentCnt, int &testsCnt)
{
    file >> studentCnt >> testsCnt;
    student *students = new student[studentCnt];

    for (int i = 0; i < studentCnt; i++)
    {
        file >> students[i].name >> students[i].id;

        // allocate dynamic array for test scores
        students[i].scores = new double[testsCnt];

        for (int j = 0; j < testsCnt; j++)
        {
            file >> students[i].scores[j];
        }

        students[i].average = 0.0;
        students[i].grade = ' ';
    }

    return students;
}

/*
Function: calcAverage
Input: array of student structs, total students, total tests
Precondition: Student data must be loaded in the struct array.
Postcondition: Calculates the average and assigns letter grade for each student.
*/
void calcAverage(student students[], int studentCnt, int testsCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        double total = 0;

        for (int j = 0; j < testsCnt; j++)
        {
            total += students[i].scores[j];
        }

        students[i].average = total / testsCnt;
        students[i].grade = findGrade(students[i].average);
    }
}

/*
Function: printReport
Input: array of student structs, total students
Precondition: Student array must contain computed averages and grades.
Postcondition: Displays a formatted report showing name, ID, average, and grade.
*/
void printReport(student students[], int studentCnt)
{
    cout << left << setw(12) << "Name"
         << setw(10) << "ID"
         << setw(10) << "Average"
         << setw(6) << "Grade" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < studentCnt; i++)
    {
        cout << left << setw(12) << students[i].name
             << setw(10) << students[i].id
             << setw(10) << fixed << setprecision(2) << students[i].average
             << setw(6) << students[i].grade << endl;
    }
}

/*
Function: freeMemory
Input: array of student structs, total students
Precondition: Dynamic memory must have been allocated.
Postcondition: Frees all dynamically allocated arrays to prevent memory leaks.
*/
void freeMemory(student students[], int studentCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        delete[] students[i].scores;
    }
    delete[] students;
}

/*
Main Function
Handles opening the file, calling all functions, and cleaning up.
*/
int main()
{
    ifstream file("student_data.txt");
    if (!file)
    {
        cout << "Error: Could not open student_data.txt file." << endl;
        return 1;
    }

    int studentCnt, testsCnt;
    student *students = getData(file, studentCnt, testsCnt);

    calcAverage(students, studentCnt, testsCnt);
    printReport(students, studentCnt);

    freeMemory(students, studentCnt);
    file.close();

    return 0;
}