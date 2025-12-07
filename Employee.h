#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

// ===============================
//      CUSTOM EXCEPTION
// ===============================
class InvalidEmployeeNumber : public runtime_error {
public:
    InvalidEmployeeNumber()
        : runtime_error("ERROR: Employee number must be between 0 and 9999.") {}
};

// ===============================
//          EMPLOYEE CLASS
// ===============================
class Employee {
protected:
    string name;
    int employeeNumber;
    string hireDate;

public:
    Employee() : name(""), employeeNumber(0), hireDate("") {}

    Employee(string n, int num, string date)
        : name(n), hireDate(date)
    {
        setEmployeeNumber(num);
    }

    // Setters
    void setName(string n) { name = n; }

    void setEmployeeNumber(int num) {
        if (num < 0 || num > 9999)
            throw InvalidEmployeeNumber();
        employeeNumber = num;
    }

    void setHireDate(string date) { hireDate = date; }

    // Getters
    string getName() const { return name; }
    int getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    // Display
    friend ostream& operator<<(ostream& os, const Employee& e) {
        os << "Name: " << e.name << "\n"
           << "Employee Number: " << e.employeeNumber << "\n"
           << "Hire Date: " << e.hireDate << "\n";
        return os;
    }
};

#endif