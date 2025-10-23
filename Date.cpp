/*
File Name: Date.cpp
Author: Bramesh Patel
Date: 10/23/2025

Description:
This program defines and demonstrates a Date class that stores and validates
month, day, and year values. It includes leap year logic, date validation,
and multiple display formats. Invalid input resets the date to 1/1/1900.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// =====================
//   CLASS DEFINITION
// =====================
class Date
{
private:
    int month;
    int day;
    int year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int y) const
    {
        return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    }

    // Helper function to determine the last day of a month
    int lastDay(int m, int y) const
    {
        switch (m)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 0; // invalid month
        }
    }

public:
    // Constructor with default parameters
    Date(int m = 1, int d = 1, int y = 1900)
    {
        setDate(m, d, y);
    }

    // Mutator function with input validation
    void setDate(int m, int d, int y)
    {
        if (m < 1 || m > 12)
        {
            cout << "Month invalid" << endl;
            month = 1; day = 1; year = 1900;
            return;
        }

        int last = lastDay(m, y);
        if (d < 1 || d > last)
        {
            cout << "Day invalid" << endl;
            month = 1; day = 1; year = 1900;
            return;
        }

        if (y < 1)
        {
            cout << "Year invalid" << endl;
            month = 1; day = 1; year = 1900;
            return;
        }

        month = m;
        day = d;
        year = y;
    }

    // Accessors
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Leap year (no parameter)
    bool isLeapYear() const
    {
        return isLeapYear(year);
    }

    // Last day (no parameter)
    int lastDay() const
    {
        return lastDay(month, year);
    }

    // Print numeric format: MM/DD/YYYY
    string printNumeric() const
    {
        ostringstream out;
        out << month << "/" << day << "/" << year;
        return out.str();
    }

    // Print long format: Month DD, YYYY
    string printLong() const
    {
        static const string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        ostringstream out;
        out << monthNames[month] << " " << day << ", " << year;
        return out.str();
    }

    // Print alternative format: DD Month YYYY
    string printLongAlt() const
    {
        static const string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        ostringstream out;
        out << day << " " << monthNames[month] << " " << year;
        return out.str();
    }
};

// =====================
//   MAIN FUNCTION
// =====================
int main()
{
    cout << "=== Testing Date Class ===" << endl;

    // Default constructor
    Date d1;
    cout << "Test default constructor: " << d1.printNumeric() << endl;

    // Valid constructor
    Date d2(2, 28, 2009);
    cout << "Test constructor with valid date: " << d2.printNumeric() << endl;

    // Invalid month
    Date d3(45, 2, 2009);
    cout << "Test constructor with invalid month (45, 2, 2009): " << d3.printNumeric() << endl;

    // Invalid day (non-leap year)
    Date d4(2, 29, 2009);
    cout << "Test constructor with invalid day (2, 29, 2009): " << d4.printNumeric() << endl;

    // Test setDate with invalid month
    cout << "\nTest setDate with bad month (13):" << endl;
    d1.setDate(13, 10, 2009);
    cout << "Result: " << d1.printNumeric() << endl;

    // Test setDate with invalid day
    cout << "\nTest setDate with bad day (4, 31, 2009):" << endl;
    d1.setDate(4, 31, 2009);
    cout << "Result: " << d1.printNumeric() << endl;

    // Test leap year invalid
    cout << "\nTest for leap year with bad date (2/29/2009):" << endl;
    d1.setDate(2, 29, 2009);
    cout << "Result: " << d1.printNumeric() << endl;

    // Test leap year valid
    cout << "\nTest for leap year with good date (2/29/2008):" << endl;
    d1.setDate(2, 29, 2008);
    cout << "Result: " << d1.printNumeric() << endl;

    // Print formats
    cout << "\nTest print formats:" << endl;
    cout << d1.printLong() << endl;
    cout << d1.printLongAlt() << endl;

    cout << "\n=== End of Tests ===" << endl;
    return 0;
}