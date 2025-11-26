/*
File Name: FactoryWorkers.cpp
Author: Bramesh Patel
Date: 11/25/2025

Description:
This program demonstrates a set of classes that represent different types
of factory employees. The classes include Employee, ProductionWorker,
ShiftSupervisor, and TeamLeader. The program creates objects from each
class and displays their information using print functions. All classes
use constructor initializer lists and reuse print functions from their
base classes.
*/

#include <iostream>
using namespace std;

#include "EmployeeData.h"

// ===============================
//          MAIN FUNCTION
// ===============================
int main()
{
    cout << "----- Testing ProductionWorker Objects -----" << endl;

    // First ProductionWorker
    ProductionWorker pw1("John Doe", "A123", "01/05/2020", 1, 22.50);
    cout << "Production Worker 1:" << endl;
    pw1.printProductionWorker();
    cout << endl;

    // Second ProductionWorker
    ProductionWorker pw2("Sarah Smith", "B456", "03/14/2021", 2, 25.75);
    cout << "Production Worker 2:" << endl;
    pw2.printProductionWorker();
    cout << endl;

    cout << "----- Testing ShiftSupervisor Object -----" << endl;

    ShiftSupervisor ss("Michael Brown", "S789", "07/20/2019", 65000, 8000);
    cout << "Shift Supervisor:" << endl;
    ss.printShiftSupervisor();
    cout << endl;

    cout << "----- Testing TeamLeader Object -----" << endl;

    TeamLeader tl("Emily Johnson", "T321", "11/10/2022",
                  1, 28.50,     // shift, pay
                  500,          // monthly bonus
                  40,           // required training hours
                  32);          // attended training hours

    cout << "Team Leader:" << endl;
    tl.printTeamLeader();
    cout << endl;

    return 0;
}
