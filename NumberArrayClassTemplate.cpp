/*
File Name: NumberArrayClassTemplate.cpp
Author: Bramesh Patel
Date: 12/08/2025

Description:
Client program that demonstrates the use of the NumberArray template
class with both integer and double arrays. The program tests constructors,
mutators, accessors, statistical functions, and exception handling
using out_of_range exceptions.
*/

#include <iostream>
#include <iomanip>
#include "NumberArray.h"
using namespace std;

int main()
{
    cout << fixed << setprecision(1);

    cout << "----- Test constructors -----\n";

    // Default constructors (size = 10)
    NumberArray<int> intArray1;
    NumberArray<double> doubleArray1;

    cout << "From default constructor: Integer array of size 10\n";
    intArray1.print();

    cout << "From default constructor: Double array of size 10\n";
    doubleArray1.print();

    // Constructor with parameters (size = 15)
    NumberArray<int> intArray2(15);
    NumberArray<double> doubleArray2(15);

    cout << "From constructor with parameters: Integer array of size 15\n";
    intArray2.print();

    cout << "From constructor with parameters: Integer array of size 15\n";
    doubleArray2.print();


    cout << "----- Test mutator -----\n";

    // Fill the integer array with random values
    cout << "Integer array filled with numbers:\n";
    for (int i = 0; i < intArray2.getSize(); i++)
        intArray2.setNumber(i, rand() % 100);
    intArray2.print();

    // Fill the double array with random decimal values
    cout << "Double array filled with numbers:\n";
    for (int i = 0; i < doubleArray2.getSize(); i++)
        doubleArray2.setNumber(i, (rand() % 1000) / 10.0);
    doubleArray2.print();


    cout << "Trying to set a number with an out of bounds index (20):\n";
    try {
        intArray2.setNumber(20, 123);
    }
    catch (out_of_range &e) {
        cout << "Integer array ...\n" << e.what() << endl;
    }

    try {
        doubleArray2.setNumber(20, 99.9);
    }
    catch (out_of_range &e) {
        cout << "Double array ...\n" << e.what() << endl;
    }


    cout << "----- Test accessors -----\n";

    cout << "Access integer item at index 5: "
         << intArray2.getNumber(5) << endl;

    cout << "Access double item at index 5: "
         << doubleArray2.getNumber(5) << endl;

    cout << "Trying to access a number with an out of bounds index (20):\n";

    try {
        intArray2.getNumber(20);
    }
    catch (out_of_range &e) {
        cout << "Integer array ...\n" << e.what() << endl;
    }

    try {
        doubleArray2.getNumber(20);
    }
    catch (out_of_range &e) {
        cout << "Double array ...\n" << e.what() << endl;
    }


    // Display statistics
    cout << "The minimum value in the integer array is: "
         << intArray2.getLowest() << endl;

    cout << "The maximum value in the integer array is: "
         << intArray2.getHighest() << endl;

    cout << "The average of the values in the integer array is: "
         << intArray2.getAverage() << endl;

    cout << "The minimum value in the double array is: "
         << doubleArray2.getLowest() << endl;

    cout << "The maximum value in the double array is: "
         << doubleArray2.getHighest() << endl;

    cout << "The average of the values in the double array is: "
         << doubleArray2.getAverage() << endl;

    cout << "----- Print arrays -----\n";

    cout << "Integer array:\n";
    intArray2.print();

    cout << "Double array:\n";
    doubleArray2.print();

    cout << "----- Test destructor -----\n";
    cout << "Exiting program, destructor will be called to free memory.\n";

    return 0;
}