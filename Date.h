/*
File Name: Date.h
Author: Bramesh Patel
Date: 10/23/2025

Description:
Header file for the Date class. The Date class stores and validates
month, day, and year values. It includes functions for leap year checking,
last day calculation, and displaying dates in multiple formats.
*/

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

    bool isLeapYear(int y) const;
    int lastDay(int m, int y) const;

public:
    // Constructors
    Date(int m = 1, int d = 1, int y = 1900);

    // Mutator
    void setDate(int m, int d, int y);

    // Accessors
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Overloaded leap year and last day functions
    bool isLeapYear() const;
    int lastDay() const;

    // Output functions
    string printNumeric() const;
    string printLong() const;
    string printLongAlt() const;
};

#endif