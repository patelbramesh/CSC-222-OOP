/*
File Name: EncapsulatedExceptions.cpp
Author: Bramesh Patel
Date: 12/07/2025

Description:
This program extends the Factory Workers OOP assignment by implementing
encapsulated exception handling for invalid employee data (invalid employee
numbers, pay rates, and shifts). It fully supports:

• Adding employees for all categories:
    - Production Worker
    - Shift Supervisor
    - Team Leader

• Viewing stored employees
• Updating employees (category-specific update menus)
• Deleting employees (category-specific delete menus)

All class data is protected and modified ONLY through setters to enforce
encapsulation. The program uses a menu-driven interface and vectors to
store employee objects dynamically.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Include class definitions
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"


// ============================================================================
//                      UTILITY: INPUT CLEANUP
// Clears leftover characters from the input buffer to prevent infinite loops.
// ============================================================================
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



// ============================================================================
//                     ADD EMPLOYEE FUNCTIONS (3 TYPES)
// Each function gathers input for a specific employee class, validates input,
// triggers exceptions if invalid, and returns the constructed employee object.
// ============================================================================


// -------------------------- Add Production Worker ---------------------------
ProductionWorker addProductionWorker()
{
    string name, date;
    int number, shift;
    double pay;

    cout << "\n========== Add Production Worker ==========\n";

    // Get name
    cout << "Enter Name: ";
    getline(cin, name);

    // Validate employee number
    while (true)
    {
        try {
            cout << "Enter Employee Number (0–9999): ";
            cin >> number;
            clearInput();

            ProductionWorker temp;
            temp.setEmployeeNumber(number); // May throw exception
            break; // Stop loop if valid
        }
        catch (InvalidEmployeeNumber &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    // Get hire date
    cout << "Enter Hire Date (MM/DD/YYYY): ";
    getline(cin, date);

    // Validate shift
    while (true)
    {
        try {
            cout << "Enter Shift (1 = Day, 2 = Night): ";
            cin >> shift;
            clearInput();

            ProductionWorker temp;
            temp.setShift(shift); // May throw exception
            break;
        }
        catch (InvalidShift &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    // Validate pay rate
    while (true)
    {
        try {
            cout << "Enter Hourly Pay Rate: ";
            cin >> pay;
            clearInput();

            ProductionWorker temp;
            temp.setPayRate(pay); // May throw exception
            break;
        }
        catch (InvalidPayRate &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    // Return fully validated object
    return ProductionWorker(name, number, date, shift, pay);
}



// -------------------------- Add Shift Supervisor ----------------------------
ShiftSupervisor addShiftSupervisor()
{
    string name, date;
    int number;
    double salary, bonus;

    cout << "\n========== Add Shift Supervisor ==========\n";

    cout << "Enter Name: ";
    getline(cin, name);

    // Validate employee number
    while (true)
    {
        try {
            cout << "Enter Employee Number (0–9999): ";
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

    // Hire date
    cout << "Enter Hire Date (MM/DD/YYYY): ";
    getline(cin, date);

    // Salary and bonus (no custom exceptions here)
    cout << "Enter Annual Salary: ";
    cin >> salary;
    clearInput();

    cout << "Enter Annual Bonus: ";
    cin >> bonus;
    clearInput();

    return ShiftSupervisor(name, number, date, salary, bonus);
}



// ------------------------------ Add Team Leader -----------------------------
TeamLeader addTeamLeader()
{
    string name, date;
    int number, shift, requiredHours, attendedHours;
    double payRate, monthlyBonus;

    cout << "\n========== Add Team Leader ==========\n";

    // Get name
    cout << "Enter Name: ";
    getline(cin, name);

    // Validate employee number
    while (true)
    {
        try {
            cout << "Enter Employee Number (0–9999): ";
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

    // Hire date
    cout << "Enter Hire Date (MM/DD/YYYY): ";
    getline(cin, date);

    // Validate shift
    while (true)
    {
        try {
            cout << "Enter Shift (1 = Day, 2 = Night): ";
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

    // Validate pay rate
    while (true)
    {
        try {
            cout << "Enter Hourly Pay Rate: ";
            cin >> payRate;
            clearInput();

            TeamLeader temp;
            temp.setPayRate(payRate);
            break;
        }
        catch (InvalidPayRate &e) {
            cout << e.what() << "\nTry again.\n";
        }
    }

    // Team leader specific fields
    cout << "Enter Monthly Bonus: ";
    cin >> monthlyBonus;
    clearInput();

    cout << "Enter Required Training Hours: ";
    cin >> requiredHours;
    clearInput();

    cout << "Enter Attended Training Hours: ";
    cin >> attendedHours;
    clearInput();

    return TeamLeader(name, number, date, shift, payRate,
                      monthlyBonus, requiredHours, attendedHours);
}



// ============================================================================
//                DISPLAY CATEGORY (Used for all employee types)
// ============================================================================
template <typename T>
void displayCategory(const vector<T>& list, const string& label)
{
    cout << "\n========== " << label << " ==========\n";

    if (list.empty()) {
        cout << "No entries found.\n";
        return;
    }

    for (int i = 0; i < list.size(); i++) {
        cout << "----- Entry #" << (i + 1) << " -----\n";
        cout << list[i] << "\n";
    }
}



// ============================================================================
//                  UPDATE FUNCTIONS FOR ALL THREE CLASSES
// These functions contain ONLY setter calls — never direct member access.
// ============================================================================


// ------------------------ Update Production Worker --------------------------
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

        switch (choice)
        {
            case 1: {
                string newName;
                cout << "Enter New Name: ";
                getline(cin, newName);
                w.setName(newName);
                break;
            }

            case 2: {
                int num;
                while (true) {
                    try {
                        cout << "Enter New Employee Number: ";
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
                string date;
                cout << "Enter New Hire Date: ";
                getline(cin, date);
                w.setHireDate(date);
                break;
            }

            case 4: {
                int sh;
                while (true) {
                    try {
                        cout << "Enter New Shift (1 or 2): ";
                        cin >> sh;
                        clearInput();
                        w.setShift(sh);
                        break;
                    }
                    catch (InvalidShift &e) {
                        cout << e.what() << "\nTry again.\n";
                    }
                }
                break;
            }

            case 5: {
                double pay;
                while (true) {
                    try {
                        cout << "Enter New Pay Rate: ";
                        cin >> pay;
                        clearInput();
                        w.setPayRate(pay);
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



// ------------------------ Update Shift Supervisor --------------------------
void updateShiftSupervisor(vector<ShiftSupervisor>& list)
{
    if (list.empty()) {
        cout << "\nNo Shift Supervisors to update.\n";
        return;
    }

    displayCategory(list, "Shift Supervisors");

    int index;
    cout << "Select entry to update: ";
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

        switch (choice)
        {
            case 1: {
                string name;
                cout << "Enter New Name: ";
                getline(cin, name);
                s.setName(name);
                break;
            }

            case 2: {
                int num;
                while (true) {
                    try {
                        cout << "Enter New Employee Number: ";
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
                cout << "Enter New Hire Date: ";
                getline(cin, date);
                s.setHireDate(date);
                break;
            }

            case 4: {
                double sal;
                cout << "Enter New Salary: ";
                cin >> sal;
                clearInput();
                s.setSalary(sal);
                break;
            }

            case 5: {
                double bonus;
                cout << "Enter New Bonus: ";
                cin >> bonus;
                clearInput();
                s.setBonus(bonus);
                break;
            }
        }

    } while (choice != 6);
}



// ------------------------------ Update Team Leader --------------------------
void updateTeamLeader(vector<TeamLeader>& list)
{
    if (list.empty()) {
        cout << "\nNo Team Leaders to update.\n";
        return;
    }

    displayCategory(list, "Team Leaders");

    int index;
    cout << "Select entry to update: ";
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
             << "7. Update Required Training Hours\n"
             << "8. Update Attended Training Hours\n"
             << "9. Back\n"
             << "Select: ";
        cin >> choice;
        clearInput();

        switch (choice)
        {
            case 1: {
                string name;
                cout << "Enter New Name: ";
                getline(cin, name);
                t.setName(name);
                break;
            }

            case 2: {
                int num;
                while (true) {
                    try {
                        cout << "Enter New Employee Number: ";
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
                cout << "Enter New Hire Date: ";
                getline(cin, date);
                t.setHireDate(date);
                break;
            }

            case 4: {
                int shift;
                while (true) {
                    try {
                        cout << "Enter New Shift: ";
                        cin >> shift;
                        clearInput();
                        t.setShift(shift);
                        break;
                    }
                    catch (InvalidShift &e) {
                        cout << e.what() << "\nTry again.\n";
                    }
                }
                break;
            }

            case 5: {
                double pay;
                while (true) {
                    try {
                        cout << "Enter New Pay Rate: ";
                        cin >> pay;
                        clearInput();
                        t.setPayRate(pay);
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
                cout << "Enter New Monthly Bonus: ";
                cin >> b;
                clearInput();
                t.setMonthlyBonus(b);
                break;
            }

            case 7: {
                int req;
                cout << "Enter New Required Hours: ";
                cin >> req;
                clearInput();
                t.setRequiredHours(req);
                break;
            }

            case 8: {
                int att;
                cout << "Enter New Attended Hours: ";
                cin >> att;
                clearInput();
                t.setAttendedHours(att);
                break;
            }
        }

    } while (choice != 9);
}



// ============================================================================
//                              DELETE ENTRY
// ============================================================================
template <typename T>
void deleteEntry(vector<T> &list, const string &label)
{
    if (list.empty()) {
        cout << "\nNo " << label << " to delete.\n";
        return;
    }

    displayCategory(list, label);

    int index;
    cout << "Select entry number to delete: ";
    cin >> index;
    clearInput();

    if (index < 1 || index > list.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    list.erase(list.begin() + (index - 1));

    cout << "Entry deleted successfully.\n";
}



// ============================================================================
//                                  MAIN MENU
// ============================================================================
int main()
{
    // Vectors storing employees in each category
    vector<ProductionWorker> workers;
    vector<ShiftSupervisor> supervisors;
    vector<TeamLeader> leaders;

    int mainChoice;

    do {
        // -------------------------- Main Menu --------------------------
        cout << "\n============= EMPLOYEE MANAGEMENT SYSTEM =============\n"
             << "1. Add Employee\n"
             << "2. View Employees\n"
             << "3. Update Employee\n"
             << "4. Delete Employee\n"
             << "5. Exit\n"
             << "Select Option: ";
        cin >> mainChoice;
        clearInput();

        switch (mainChoice)
        {
            // ============================================================
            //                     ADD EMPLOYEE
            // ============================================================
            case 1: {
                int type;
                cout << "\n--- Select Employee Type to Add ---\n"
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

            // ============================================================
            //                     VIEW ALL EMPLOYEES
            // ============================================================
            case 2:
                displayCategory(workers, "Production Workers");
                displayCategory(supervisors, "Shift Supervisors");
                displayCategory(leaders, "Team Leaders");
                break;

            // ============================================================
            //                     UPDATE EMPLOYEE
            // ============================================================
            case 3: {
                int type;
                cout << "\n--- Select Category to Update ---\n"
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
                    cout << "Invalid selection.\n";

                break;
            }

            // ============================================================
            //                     DELETE EMPLOYEE
            // ============================================================
            case 4: {
                int type;
                cout << "\n--- Select Category to Delete From ---\n"
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
                    cout << "Invalid selection.\n";

                break;
            }

            // ============================================================
            //                          EXIT
            // ============================================================
            case 5:
                cout << "Exiting program... Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (mainChoice != 5);

    return 0;
}