#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

// ===============================
//      CUSTOM EXCEPTIONS
// ===============================
class InvalidShift : public runtime_error {
public:
    InvalidShift() : runtime_error("ERROR: Shift must be 1 (Day) or 2 (Night).") {}
};

class InvalidPayRate : public runtime_error {
public:
    InvalidPayRate() : runtime_error("ERROR: Pay rate cannot be negative.") {}
};

// ===============================
//      PRODUCTION WORKER CLASS
// ===============================
class ProductionWorker : public Employee {
private:
    int shift;
    double payRate;

public:
    ProductionWorker() : Employee(), shift(1), payRate(0.0) {}

    ProductionWorker(string n, int num, string date, int s, double p)
        : Employee(n, num, date)
    {
        setShift(s);
        setPayRate(p);
    }

    // Setters
    void setShift(int s) {
        if (s != 1 && s != 2)
            throw InvalidShift();
        shift = s;
    }

    void setPayRate(double p) {
        if (p < 0)
            throw InvalidPayRate();
        payRate = p;
    }

    // Getters
    int getShift() const { return shift; }
    double getPayRate() const { return payRate; }

    friend ostream& operator<<(ostream& os, const ProductionWorker& p) {
        os << (Employee)p;
        os << "Shift: " << (p.shift == 1 ? "Day" : "Night") << "\n"
           << "Pay Rate: $" << p.payRate << "\n";
        return os;
    }
};

#endif