/*
File Name: ParkingTicketSimulator.cpp
Author: Bramesh Patel
Date: 11/08/2025

Description:
Main driver program for the Parking Ticket Simulator project.
It includes "ParkingSystem.h" and demonstrates multiple scenarios
of parking enforcement including legal and illegal parking cases.
*/

#include "ParkingSystem.h"

int main()
{
    cout << "===== Parking Ticket Simulator =====" << endl;

    // Scenario 1: Car parked legally
    cout << "\n--- Scenario 1: Car Parked Legally ---" << endl;
    ParkedCar car1("Toyota", "Camry", "Red", "XYZ123", 30);
    ParkingMeter meter1(40);
    PoliceOfficer officer1("John Doe", "5678");
    officer1.inspectCar(car1, meter1);

    // Scenario 2: Car parked illegally (less than one hour over)
    cout << "\n--- Scenario 2: Car Parked Illegally (< 1 Hour Over) ---" << endl;
    ParkedCar car2("Honda", "Accord", "Blue", "ABC987", 70);
    ParkingMeter meter2(60);
    PoliceOfficer officer2("Jane Smith", "1234");
    officer2.inspectCar(car2, meter2);

    // Scenario 3: Car parked illegally (multiple hours over)
    cout << "\n--- Scenario 3: Car Parked Illegally (Multiple Hours Over) ---" << endl;
    ParkedCar car3("Ford", "Mustang", "Black", "LMN456", 190);
    ParkingMeter meter3(60);
    PoliceOfficer officer3("James Brown", "4321");
    officer3.inspectCar(car3, meter3);

    // Scenario 4: Multiple cars inspected by one officer
    cout << "\n--- Scenario 4: Multiple Cars in Parking Lot ---" << endl;
    PoliceOfficer officer4("Anna Lee", "7788");
    ParkedCar cars[] = {
        ParkedCar("Tesla", "Model 3", "White", "TES123", 90),
        ParkedCar("BMW", "X5", "Black", "BMW555", 50),
        ParkedCar("Nissan", "Altima", "Gray", "ALT777", 140)};
    ParkingMeter meters[] = {
        ParkingMeter(60),
        ParkingMeter(60),
        ParkingMeter(120)};

    for (int i = 0; i < 3; i++)
    {
        officer4.inspectCar(cars[i], meters[i]);
    }

    cout << "\n===== Simulation Completed =====" << endl;
    return 0;
}