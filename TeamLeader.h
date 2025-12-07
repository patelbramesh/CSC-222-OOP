#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredHours;
    int attendedHours;

public:
    TeamLeader()
        : ProductionWorker(), monthlyBonus(0), requiredHours(0), attendedHours(0) {}

    TeamLeader(string n, int num, string date, int shift, double pay,
               double bonus, int req, int attended)
        : ProductionWorker(n, num, date, shift, pay),
          monthlyBonus(bonus), requiredHours(req), attendedHours(attended) {}

    // Setters
    void setMonthlyBonus(double b) { monthlyBonus = b; }
    void setRequiredHours(int r) { requiredHours = r; }
    void setAttendedHours(int a) { attendedHours = a; }

    // Getters
    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredHours() const { return requiredHours; }
    int getAttendedHours() const { return attendedHours; }

    friend ostream& operator<<(ostream& os, const TeamLeader& t) {
        os << (ProductionWorker)t;
        os << "Monthly Bonus: $" << t.monthlyBonus << "\n"
           << "Required Training Hours: " << t.requiredHours << "\n"
           << "Attended Training Hours: " << t.attendedHours << "\n";
        return os;
    }
};

#endif