/*
File Name: ParkingSystem.h
Author: Bramesh Patel
Date: 11/08/2025

Description:
This header file defines all classes used in the Parking Ticket Simulator project:
ParkedCar, ParkingMeter, ParkingTicket, and PoliceOfficer.

Each class is responsible for storing and managing specific data related to a
real-world parking system. The PoliceOfficer class interacts with ParkedCar
and ParkingMeter objects to determine violations and issue ParkingTicket objects.
*/

#ifndef PARKING_SYSTEM_H
#define PARKING_SYSTEM_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
Class Name: ParkedCar
Description:
Represents a car parked in a parking spot, storing information such as
make, model, color, license number, and minutes parked.
*/
class ParkedCar
{
private:
    string make;
    string model;
    string color;
    string licenseNumber;
    int parkedMinutes;

public:
    ParkedCar(string mk = "", string mdl = "", string clr = "", string lic = "", int mins = 0)
    {
        make = mk;
        model = mdl;
        color = clr;
        licenseNumber = lic;
        parkedMinutes = mins;
    }

    // Accessors
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    string getLicenseNumber() const { return licenseNumber; }
    int getParkedMinutes() const { return parkedMinutes; }
};

/*
Class Name: ParkingMeter
Description:
Represents a parking meter that stores the number of minutes
of purchased parking time.
*/
class ParkingMeter
{
private:
    int purchasedMinutes;

public:
    ParkingMeter(int minutes = 0)
    {
        purchasedMinutes = minutes;
    }

    int getPurchasedMinutes() const { return purchasedMinutes; }
};

/*
Class Name: ParkingTicket
Description:
Represents a parking ticket issued to a car parked beyond the
purchased time limit. Includes calculation of fine based on
over-parked duration and details of the issuing officer.
*/
class ParkingTicket
{
private:
    string carMake;
    string carModel;
    string carColor;
    string carLicense;
    string officerName;
    string officerBadge;
    int minutesOver;
    double fineAmount;

public:
    ParkingTicket(const ParkedCar &car, const string &name, const string &badge, int overMinutes)
    {
        carMake = car.getMake();
        carModel = car.getModel();
        carColor = car.getColor();
        carLicense = car.getLicenseNumber();
        officerName = name;
        officerBadge = badge;
        minutesOver = overMinutes;
        fineAmount = calculateFine(overMinutes);
    }

    double calculateFine(int overMinutes)
    {
        if (overMinutes <= 0)
            return 0.0;

        int hours = ceil(overMinutes / 60.0);
        double totalFine = 25.0;
        if (hours > 1)
            totalFine += (hours - 1) * 10.0;
        return totalFine;
    }

    void printTicket() const
    {
        cout << "\n*** Parking Ticket ***" << endl;
        cout << "Officer: " << officerName
             << "  Badge Number: " << officerBadge << endl;
        cout << "Vehicle License Number: " << carLicense << endl;
        cout << "Make: " << carMake << "  Model: " << carModel
             << "  Color: " << carColor << endl;
        cout << "Minutes Over: " << minutesOver
             << "  Fine: $" << fineAmount << endl;
    }
};

/*
Class Name: PoliceOfficer
Description:
Simulates a police officer responsible for inspecting parked cars.
If the car’s parked time exceeds the purchased time, a parking ticket
is issued dynamically and printed to the console.
*/
class PoliceOfficer
{
private:
    string officerName;
    string badgeNumber;

public:
    PoliceOfficer(string name = "", string badge = "")
    {
        officerName = name;
        badgeNumber = badge;
    }

    void inspectCar(const ParkedCar &car, const ParkingMeter &meter)
    {
        cout << "\nInspecting car [" << car.getLicenseNumber() << "]..." << endl;
        int parked = car.getParkedMinutes();
        int purchased = meter.getPurchasedMinutes();

        if (parked > purchased)
        {
            int overtime = parked - purchased;
            ParkingTicket *ticket = new ParkingTicket(car, officerName, badgeNumber, overtime);
            ticket->printTicket();
            delete ticket; // clean up after display
        }
        else
        {
            cout << "No violation detected. Car is parked legally.\n";
        }
    }
};

#endif