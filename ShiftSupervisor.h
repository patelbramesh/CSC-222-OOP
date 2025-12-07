#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor : public Employee {
private:
    double salary;
    double bonus;

public:
    ShiftSupervisor() : Employee(), salary(0), bonus(0) {}

    ShiftSupervisor(string n, int num, string date, double s, double b)
        : Employee(n, num, date), salary(s), bonus(b) {}

    void setSalary(double s) { salary = s; }
    void setBonus(double b) { bonus = b; }

    double getSalary() const { return salary; }
    double getBonus() const { return bonus; }

    friend ostream& operator<<(ostream& os, const ShiftSupervisor& s) {
        os << (Employee)s;
        os << "Salary: $" << s.salary << "\n"
           << "Bonus: $" << s.bonus << "\n";
        return os;
    }
};

#endif