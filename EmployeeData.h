// EmployeeData.h
// All class definitions for Employee, ProductionWorker, ShiftSupervisor, and TeamLeader.
// Each class uses constructor initializer lists and includes inline documentation.

#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H

#include <iostream>
#include <string>
using namespace std;

// =============================================================
//                     EMPLOYEE CLASS
// =============================================================
class Employee {
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
    // Default Constructor
    Employee() : name(""), employeeNumber(""), hireDate("") {}

    // Parameterized Constructor
    // Preconditions: name, employee number, and hire date must be valid strings.
    // Postconditions: Employee object is created with the given data.
    Employee(string n, string eNum, string hDate)
        : name(n), employeeNumber(eNum), hireDate(hDate) {}

    // Accessors
    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    // Mutators
    void setName(string n) { name = n; }
    void setEmployeeNumber(string e) { employeeNumber = e; }
    void setHireDate(string h) { hireDate = h; }

    // Print function
    void printEmployee() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

// =============================================================
//                PRODUCTION WORKER CLASS
// =============================================================
class ProductionWorker : public Employee {
protected:
    int shift;          // 1 = day, 2 = night
    double payRate;

public:
    // Default Constructor
    ProductionWorker() : Employee(), shift(1), payRate(0.0) {}

    // Parameterized Constructor
    ProductionWorker(string n, string eNum, string hDate, int s, double p)
        : Employee(n, eNum, hDate), shift(s), payRate(p) {}

    // Accessors
    int getShift() const { return shift; }
    double getPayRate() const { return payRate; }

    // Mutators
    void setShift(int s) { shift = s; }
    void setPayRate(double p) { payRate = p; }

    // Print function
    void printProductionWorker() const {
        printEmployee();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << payRate << endl;
    }
};

// =============================================================
//                SHIFT SUPERVISOR CLASS
// =============================================================
class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor() : Employee(), annualSalary(0.0), annualBonus(0.0) {}

    ShiftSupervisor(string n, string eNum, string hDate, double salary, double bonus)
        : Employee(n, eNum, hDate), annualSalary(salary), annualBonus(bonus) {}

    // Accessors
    double getSalary() const { return annualSalary; }
    double getBonus() const { return annualBonus; }

    // Mutators
    void setSalary(double s) { annualSalary = s; }
    void setBonus(double b) { annualBonus = b; }

    void printShiftSupervisor() const {
        printEmployee();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Production Bonus: $" << annualBonus << endl;
    }
};

// =============================================================
//                TEAM LEADER CLASS
// =============================================================
class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    TeamLeader()
        : ProductionWorker(), monthlyBonus(0.0),
          requiredTrainingHours(0), attendedTrainingHours(0) {}

    TeamLeader(string n, string eNum, string hDate,
               int s, double p,
               double bonus, int required, int attended)
        : ProductionWorker(n, eNum, hDate, s, p),
          monthlyBonus(bonus),
          requiredTrainingHours(required),
          attendedTrainingHours(attended) {}

    // Accessors
    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTraining() const { return requiredTrainingHours; }
    int getAttendedTraining() const { return attendedTrainingHours; }

    // Mutators
    void setMonthlyBonus(double b) { monthlyBonus = b; }
    void setRequiredTraining(int r) { requiredTrainingHours = r; }
    void setAttendedTraining(int a) { attendedTrainingHours = a; }

    void printTeamLeader() const {
        printProductionWorker();
        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

#endif
