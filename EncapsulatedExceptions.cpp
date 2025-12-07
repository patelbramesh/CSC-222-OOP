/*
File Name: EncapsulatedExceptions.cpp
Author: Bramesh Patel
Date: 12/07/2025

Description:
This program enhances the Factory Workers assignment by adding full 
exception handling, category-specific update/delete menus, strict 
encapsulation, and separate class handling for ProductionWorker, 
ShiftSupervisor, and TeamLeader. All employee records are stored in 
vectors and can be viewed, updated, or deleted independently.

Menus:
1. Add Employees by Category
2. View All Employees
3. Update Employees (by category)
4. Delete Employees (by category)
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

// ===============================
//      Input Cleanup Function
// ===============================
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ========================================================================
//               ADD PRODUCTION WORKER
// ========================================================================
ProductionWorker addProductionWorker()
{
    string name, date;
    int number, shift;
    double pay;

    cout << "\n--- Add Production Worker ---\n";

    cout << "Name: ";
    getline(cin, name);

    // Employee Number
    while (true) {
        try {
            cout << "Employee Number (0-9999): ";
            cin >> number;
            clearInput();
            ProductionWorker temp;
            temp.setEmployeeNumber(number);
            break;
        }
        catch (InvalidEmployeeNumber &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    cout << "Hire Date: ";
    getline(cin, date);

    // Shift
    while (true) {
        try {
            cout << "Shift (1=Day, 2=Night): ";
            cin >> shift;
            clearInput();
            ProductionWorker temp;
            temp.setShift(shift);
            break;
        }
        catch (InvalidShift &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    // Pay Rate
    while (true) {
        try {
            cout << "Hourly Pay Rate: ";
            cin >> pay;
            clearInput();
            ProductionWorker temp;
            temp.setPayRate(pay);
            break;
        }
        catch (InvalidPayRate &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    return ProductionWorker(name, number, date, shift, pay);
}

// ========================================================================
//               ADD SHIFT SUPERVISOR
// ========================================================================
ShiftSupervisor addShiftSupervisor()
{
    string name, date;
    int number;
    double salary, bonus;

    cout << "\n--- Add Shift Supervisor ---\n";

    cout << "Name: ";
    getline(cin, name);

    while (true) {
        try {
            cout << "Employee Number (0-9999): ";
            cin >> number;
            clearInput();
            Employee temp;
            temp.setEmployeeNumber(number);
            break;
        }
        catch (InvalidEmployeeNumber &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    cout << "Hire Date: ";
    getline(cin, date);

    cout << "Salary: ";
    cin >> salary;
    clearInput();

    cout << "Bonus: ";
    cin >> bonus;
    clearInput();

    return ShiftSupervisor(name, number, date, salary, bonus);
}

// ========================================================================
//               ADD TEAM LEADER
// ========================================================================
TeamLeader addTeamLeader()
{
    string name, date;
    int number, shift, required, attended;
    double pay, bonus;

    cout << "\n--- Add Team Leader ---\n";

    cout << "Name: ";
    getline(cin, name);

    while (true) {
        try {
            cout << "Employee Number (0-9999): ";
            cin >> number;
            clearInput();
            Employee temp;
            temp.setEmployeeNumber(number);
            break;
        }
        catch (InvalidEmployeeNumber &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    cout << "Hire Date: ";
    getline(cin, date);

    while (true) {
        try {
            cout << "Shift (1=Day, 2=Night): ";
            cin >> shift;
            clearInput();
            TeamLeader temp;
            temp.setShift(shift);
            break;
        }
        catch (InvalidShift &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    while (true) {
        try {
            cout << "Hourly Pay Rate: ";
            cin >> pay;
            clearInput();
            TeamLeader temp;
            temp.setPayRate(pay);
            break;
        }
        catch (InvalidPayRate &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    cout << "Monthly Bonus: ";
    cin >> bonus;
    clearInput();

    cout << "Required Training Hours: ";
    cin >> required;
    clearInput();

    cout << "Attended Training Hours: ";
    cin >> attended;
    clearInput();

    return TeamLeader(name, number, date, shift, pay, bonus, required, attended);
}

// ========================================================================
//               DISPLAY CATEGORY
// ========================================================================
template <typename T>
void displayCategory(const vector<T>& list, const string &label)
{
    cout << "\n--- " << label << " ---\n";

    if (list.empty()) {
        cout << "No records found.\n";
        return;
    }

    for (int i = 0; i < list.size(); i++) {
        cout << "[" << (i + 1) << "]\n" << list[i] << "\n";
    }
}

// ========================================================================
//               UPDATE PRODUCTION WORKER
// ========================================================================
void updateProductionWorker(vector<ProductionWorker>& workers)
{
    if (workers.empty()) {
        cout << "\nNo Production Workers to update.\n";
        return;
    }

    displayCategory(workers, "Production Workers");

    int index;
    cout << "Select worker number to update: ";
    cin >> index;
    clearInput();

    if (index < 1 || index > workers.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    ProductionWorker &w = workers[index - 1];

    int choice;
    do {
        cout << "\n--- Update Production Worker ---\n"
             << "1. Update Name\n"
             << "2. Update Employee Number\n"
             << "3. Update Hire Date\n"
             << "4. Update Shift\n"
             << "5. Update Pay Rate\n"
             << "6. Back\n"
             << "Select: ";
        cin >> choice;
        clearInput();

        switch (choice) {

        case 1: {
            string newName;
            cout << "New Name: ";
            getline(cin, newName);
            w.setName(newName);
            break;
        }

        case 2: {
            int num;
            while (true) {
                try {
                    cout << "New Employee Number: ";
                    cin >> num;
                    clearInput();
                    w.setEmployeeNumber(num);
                    break;
                }
                catch (InvalidEmployeeNumber &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 3: {
            string newDate;
            cout << "New Hire Date: ";
            getline(cin, newDate);
            w.setHireDate(newDate);
            break;
        }

        case 4: {
            int s;
            while (true) {
                try {
                    cout << "New Shift (1=Day, 2=Night): ";
                    cin >> s;
                    clearInput();
                    w.setShift(s);
                    break;
                }
                catch (InvalidShift &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 5: {
            double p;
            while (true) {
                try {
                    cout << "New Pay Rate: ";
                    cin >> p;
                    clearInput();
                    w.setPayRate(p);
                    break;
                }
                catch (InvalidPayRate &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        }

    } while (choice != 6);
}

// ========================================================================
//            UPDATE SHIFT SUPERVISOR
// ========================================================================
void updateShiftSupervisor(vector<ShiftSupervisor>& list)
{
    if (list.empty()) {
        cout << "\nNo Shift Supervisors to update.\n";
        return;
    }

    displayCategory(list, "Shift Supervisors");

    int index;
    cout << "Select supervisor number to update: ";
    cin >> index;
    clearInput();

    if (index < 1 || index > list.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    ShiftSupervisor &s = list[index - 1];

    int choice;
    do {
        cout << "\n--- Update Shift Supervisor ---\n"
             << "1. Update Name\n"
             << "2. Update Employee Number\n"
             << "3. Update Hire Date\n"
             << "4. Update Salary\n"
             << "5. Update Bonus\n"
             << "6. Back\n"
             << "Select: ";
        cin >> choice;
        clearInput();

        switch (choice) {

        case 1: {
            string name;
            cout << "New Name: ";
            getline(cin, name);
            s.setName(name);
            break;
        }

        case 2: {
            int num;
            while (true) {
                try {
                    cout << "New Employee Number: ";
                    cin >> num;
                    clearInput();
                    s.setEmployeeNumber(num);
                    break;
                }
                catch (InvalidEmployeeNumber &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 3: {
            string date;
            cout << "New Hire Date: ";
            getline(cin, date);
            s.setHireDate(date);
            break;
        }

        case 4: {
            double sal;
            cout << "New Salary: ";
            cin >> sal;
            clearInput();
            s.setSalary(sal);
            break;
        }

        case 5: {
            double b;
            cout << "New Bonus: ";
            cin >> b;
            clearInput();
            s.setBonus(b);
            break;
        }
        }

    } while (choice != 6);
}

// ========================================================================
//              UPDATE TEAM LEADER
// ========================================================================
void updateTeamLeader(vector<TeamLeader>& list)
{
    if (list.empty()) {
        cout << "\nNo Team Leaders to update.\n";
        return;
    }

    displayCategory(list, "Team Leaders");

    int index;
    cout << "Select team leader number to update: ";
    cin >> index;
    clearInput();

    if (index < 1 || index > list.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    TeamLeader &t = list[index - 1];

    int choice;
    do {
        cout << "\n--- Update Team Leader ---\n"
             << "1. Update Name\n"
             << "2. Update Employee Number\n"
             << "3. Update Hire Date\n"
             << "4. Update Shift\n"
             << "5. Update Pay Rate\n"
             << "6. Update Monthly Bonus\n"
             << "7. Update Required Hours\n"
             << "8. Update Attended Hours\n"
             << "9. Back\n"
             << "Select: ";
        cin >> choice;
        clearInput();

        switch (choice) {

        case 1: {
            string name;
            cout << "New Name: ";
            getline(cin, name);
            t.setName(name);
            break;
        }

        case 2: {
            int num;
            while (true) {
                try {
                    cout << "New Employee Number: ";
                    cin >> num;
                    clearInput();
                    t.setEmployeeNumber(num);
                    break;
                }
                catch (InvalidEmployeeNumber &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 3: {
            string date;
            cout << "New Hire Date: ";
            getline(cin, date);
            t.setHireDate(date);
            break;
        }

        case 4: {
            int sh;
            while (true) {
                try {
                    cout << "New Shift (1=Day, 2=Night): ";
                    cin >> sh;
                    clearInput();
                    t.setShift(sh);
                    break;
                }
                catch (InvalidShift &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 5: {
            double p;
            while (true) {
                try {
                    cout << "New Pay Rate: ";
                    cin >> p;
                    clearInput();
                    t.setPayRate(p);
                    break;
                }
                catch (InvalidPayRate &e) {
                    cout << e.what() << "\nTry again.\n";
                }
            }
            break;
        }

        case 6: {
            double b;
            cout << "New Monthly Bonus: ";
            cin >> b;
            clearInput();
            t.setMonthlyBonus(b);
            break;
        }

        case 7: {
            int req;
            cout << "New Required Hours: ";
            cin >> req;
            clearInput();
            t.setRequiredHours(req);
            break;
        }

        case 8: {
            int att;
            cout << "New Attended Hours: ";
            cin >> att;
            clearInput();
            t.setAttendedHours(att);
            break;
        }

        }

    } while (choice != 9);
}

// ========================================================================
//               DELETE ENTRY
// ========================================================================
template<typename T>
void deleteEntry(vector<T>& list, const string &label)
{
    if (list.empty()) {
        cout << "\nNo " << label << " to delete.\n";
        return;
    }

    displayCategory(list, label);

    int index;
    cout << "Select index to delete: ";
    cin >> index;
    clearInput();

    if (index < 1 || index > list.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    list.erase(list.begin() + (index - 1));
    cout << "Deleted successfully.\n";
}

// ========================================================================
//                               MAIN
// ========================================================================
int main()
{
    vector<ProductionWorker> workers;
    vector<ShiftSupervisor> supervisors;
    vector<TeamLeader> leaders;

    int menu;

    do {
        cout << "\n=========== Employee Menu ===========\n"
             << "1. Add Employee\n"
             << "2. View Employees\n"
             << "3. Update Employee\n"
             << "4. Delete Employee\n"
             << "5. Exit\n"
             << "Select: ";
        cin >> menu;
        clearInput();

        switch (menu)
        {
        case 1: {
            int type;
            cout << "\n--- Add Employee Type ---\n"
                 << "1. Production Worker\n"
                 << "2. Shift Supervisor\n"
                 << "3. Team Leader\n"
                 << "Select: ";
            cin >> type;
            clearInput();

            if (type == 1)
                workers.push_back(addProductionWorker());
            else if (type == 2)
                supervisors.push_back(addShiftSupervisor());
            else if (type == 3)
                leaders.push_back(addTeamLeader());
            else
                cout << "Invalid category.\n";

            break;
        }

        case 2:
            displayCategory(workers, "Production Workers");
            displayCategory(supervisors, "Shift Supervisors");
            displayCategory(leaders, "Team Leaders");
            break;

        case 3: {
            int type;
            cout << "\n--- Update Category ---\n"
                 << "1. Production Worker\n"
                 << "2. Shift Supervisor\n"
                 << "3. Team Leader\n"
                 << "Select: ";
            cin >> type;
            clearInput();

            if (type == 1)
                updateProductionWorker(workers);
            else if (type == 2)
                updateShiftSupervisor(supervisors);
            else if (type == 3)
                updateTeamLeader(leaders);
            else
                cout << "Invalid category.\n";

            break;
        }

        case 4: {
            int type;
            cout << "\n--- Delete Category ---\n"
                 << "1. Production Worker\n"
                 << "2. Shift Supervisor\n"
                 << "3. Team Leader\n"
                 << "Select: ";
            cin >> type;
            clearInput();

            if (type == 1)
                deleteEntry(workers, "Production Workers");
            else if (type == 2)
                deleteEntry(supervisors, "Shift Supervisors");
            else if (type == 3)
                deleteEntry(leaders, "Team Leaders");
            else
                cout << "Invalid category.\n";

            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid menu option.\n";
        }

    } while (menu != 5);

    return 0;
}