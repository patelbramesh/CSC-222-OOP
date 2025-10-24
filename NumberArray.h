/*
File Name: NumberArray.h
Author: Bramesh Patel
Date: 10/23/2025

Description:
Header file for the NumberArray class. The class dynamically allocates
a floating-point array and provides functions to set, get, and calculate
statistics like minimum, maximum, and average.
*/

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
using namespace std;

class NumberArray
{
private:
    double *numbers;  // pointer to dynamic array
    int size;         // array size

public:
    static const int MAX_SIZE = 10;       // default array size
    static const double DEFAULT_VALUE;    // default value for invalid access

    // Constructors and Destructor
    NumberArray(int s = MAX_SIZE);
    ~NumberArray();

    // Mutator
    void setNumber(int index, double value);

    // Accessor
    double getNumber(int index) const;

    // Statistical functions
    double getHighest() const;
    double getLowest() const;
    double getAverage() const;

    // Display
    void print() const;
};

#endif