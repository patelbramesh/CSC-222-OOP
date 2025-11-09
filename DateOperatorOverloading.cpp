/*
File Name: DateOperatorOverloading.cpp
Author: Bramesh Patel
Date: 11/08/2025

Description:
This program demonstrates operator overloading using a Date class.
It includes overloaded operators for increment (++), decrement (--),
subtraction (-), stream insertion (<<), and extraction (>>).

The program ensures proper date validation, leap year handling,
and accurate transitions between months and years. It also verifies
invalid inputs and displays the results of all test cases defined
in the project’s test plan.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*
Class Name: Date

Description:
The Date class represents a calendar date with day, month, and year.
It includes functions to validate dates, handle leap years, and perform
date arithmetic using overloaded operators.
*/
class Date
{
private:
    int day, month, year;

    /*
    Function Name: isLeapYear
    Input:
     - y: integer representing a year
    Output:
     - Returns true if the year is a leap year, false otherwise
    */
    bool isLeapYear(int y) const
    {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    /*
    Function Name: daysInMonth
    Input:
     - m: integer representing a month
     - y: integer representing a year
    Output:
     - Returns number of days in the given month/year
    */
    int daysInMonth(int m, int y) const
    {
        if (m == 2)
            return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        return 31;
    }

    /*
    Function Name: isValidDate
    Input:
     - d: integer day
     - m: integer month
     - y: integer year
    Output:
     - Returns true if the date is valid, false otherwise
    */
    bool isValidDate(int d, int m, int y) const
    {
        return (y > 0 && m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(m, y));
    }

public:
    /*
    Constructor Name: Date
    Description:
     - Initializes a Date object. If invalid parameters are given,
       defaults to January 1, 2000.
    */
    Date(int d = 1, int m = 1, int y = 2000)
    {
        if (isValidDate(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    /*
    Function Name: setDate
    Description:
     - Sets the date to user-defined values if valid.
       Otherwise, displays an error message.
    */
    void setDate(int d, int m, int y)
    {
        if (isValidDate(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
            cout << "Invalid date entered!\n";
    }

    /*
    Operator: Prefix Increment (++date)
    Description:
     - Moves the date forward by one day and handles
       month and year boundaries.
    */
    Date &operator++()
    {
        day++;
        if (day > daysInMonth(month, year))
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    /*
    Operator: Postfix Increment (date++)
    Description:
     - Increments the date but returns the original value.
    */
    Date operator++(int)
    {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    /*
    Operator: Prefix Decrement (--date)
    Description:
     - Moves the date backward by one day and handles
       transitions to previous month/year.
    */
    Date &operator--()
    {
        day--;
        if (day < 1)
        {
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    /*
    Operator: Postfix Decrement (date--)
    Description:
     - Decrements the date but returns the original value.
    */
    Date operator--(int)
    {
        Date temp = *this;
        --(*this);
        return temp;
    }

    /*
    Operator: Subtraction (date1 - date2)
    Description:
     - Returns the absolute number of days between two Date objects.
    */
    int operator-(const Date &other) const
    {
        auto daysFromStart = [&](const Date &d)
        {
            int total = d.day;
            for (int i = 1; i < d.month; i++)
                total += daysInMonth(i, d.year);
            for (int y = 1; y < d.year; y++)
                total += isLeapYear(y) ? 366 : 365;
            return total;
        };

        return abs(daysFromStart(*this) - daysFromStart(other));
    }

    /*
    Operator: Stream Insertion (<<)
    Description:
     - Outputs the date in the format: Month Day, Year
    */
    friend ostream &operator<<(ostream &out, const Date &d)
    {
        static const string months[] = {"", "January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
        out << months[d.month] << " " << d.day << ", " << d.year;
        return out;
    }

    /*
    Operator: Stream Extraction (>>)
    Description:
     - Prompts the user to enter a date and validates it.
    */
    friend istream &operator>>(istream &in, Date &d)
    {
        int dd, mm, yy;
        cout << "Enter date (mm dd yyyy): ";
        in >> mm >> dd >> yy;

        if (d.isValidDate(dd, mm, yy))
            d.setDate(dd, mm, yy);
        else
            cout << "Invalid date entered!\n";

        return in;
    }
};

/*
Function Name: main
Description:
Tests all functionalities of the Date class including constructors,
setDate, operator overloads, and stream operators. Displays results
for each test case to verify correct implementation.
*/
int main()
{
    // 1. Default constructor
    Date d1;
    cout << "Default constructor: " << d1 << endl;

    // 2. Parameterized constructor
    Date d2(18, 4, 2014);
    cout << "Parameterized constructor: " << d2 << endl;

    // 3. Test setDate with valid date
    d1.setDate(29, 2, 2008);
    cout << "Valid leap year date: " << d1 << endl;

    // 4–6. Invalid dates
    d1.setDate(13, 45, 2018);
    d1.setDate(4, 31, 2000);
    d1.setDate(2, 29, 2009);

    // 7–8. Subtraction test
    Date d3(10, 4, 2014), d4(18, 4, 2014);
    cout << "Days between " << d4 << " and " << d3 << ": " << (d4 - d3) << " days\n";

    Date d5(2, 2, 2006), d6(10, 11, 2003);
    cout << "Days between " << d5 << " and " << d6 << ": " << (d5 - d6) << " days\n";

    // 9–10. Test ++ and -- with leap year
    d1.setDate(29, 2, 2008);
    cout << "Original: " << d1 << endl;
    ++d1;
    cout << "After prefix ++: " << d1 << endl;
    --d1;
    cout << "After prefix --: " << d1 << endl;

    d1++;
    cout << "After postfix ++: " << d1 << endl;
    d1--;
    cout << "After postfix --: " << d1 << endl;

    // 11–12. Test year transition
    d1.setDate(31, 12, 2024);
    cout << "Original: " << d1 << endl;
    d1++;
    cout << "After postfix ++: " << d1 << endl;
    --d1;
    cout << "After prefix --: " << d1 << endl;

    // 13–14. Stream operators
    Date userDate;
    cin >> userDate;
    cout << "You entered: " << userDate << endl;

    cout << "\nAll test cases completed successfully.\n";

    return 0;
}