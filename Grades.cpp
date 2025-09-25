/*
File Name: Grades.cpp
Author: Bramesh Patel
Date: 09/24/2025

Description:
This program reads student names and their test scores from a file.
- It calculates the average score for each student.
- It assigns a letter grade based on the average.
- It prints a formatted report with names, averages, and grades.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Global Constants

const int MAX_STUDENTS = 100; // maximum size
const int TESTS = 5;          // number of test scores per student

// Reads data from file into arrays, returns number of students

int readData(ifstream &inFile, string names[], int scores[][TESTS]) {
    int count = 0;
    while (inFile >> names[count]) {
        for (int j = 0; j < TESTS; j++) {
            inFile >> scores[count][j];
        }
        count++;
    }
    return count;
}

// Calculates averages for each student

void calculateAverages(int scores[][TESTS], double averages[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        int total = 0;
        for (int j = 0; j < TESTS; j++) {
            total += scores[i][j];
        }
        averages[i] = static_cast<double>(total) / TESTS;
    }
}

// Converts average to letter grade

char calculateLetterGrade(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Prints formatted report

void printReport(string names[], double averages[], char grades[], int studentCount) {
    cout << left << setw(12) << "Name"
         << setw(10) << "Average"
         << setw(8) << "Grade" << endl;
    cout << "-----------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(12) << names[i]
             << setw(10) << fixed << setprecision(2) << averages[i]
             << setw(8) << grades[i] << endl;
    }
}

int main() {
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS][TESTS];
    double averages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];

    ifstream inFile("StudentGrades.txt");
    if (!inFile) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    // Read file into arrays
    int studentCount = readData(inFile, names, scores);

    // Calculate averages
    calculateAverages(scores, averages, studentCount);

    // Assign letter grades
    for (int i = 0; i < studentCount; i++) {
        grades[i] = calculateLetterGrade(averages[i]);
    }

    // Print report
    printReport(names, averages, grades, studentCount);

    inFile.close();
    return 0;
}