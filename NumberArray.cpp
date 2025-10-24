/*
File Name: NumberArray.cpp
Author: Bramesh Patel
Date: 10/23/2025

Description:
This program defines and demonstrates a NumberArray class.
The class dynamically allocates a floating-point array and provides
functions to store, retrieve, and calculate statistics such as
minimum, maximum, and average. The destructor frees memory when the
object goes out of scope.
*/

#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

// ===============================
//        CLASS DEFINITION
// ===============================
class NumberArray
{
private:
    double *numbers;     // pointer to dynamic array
    int size;            // size of the array

public:
    static const int MAX_SIZE = 10;       // default size
    static const double DEFAULT_VALUE;    // default for invalid access

    // Constructor
    NumberArray(int s = MAX_SIZE)
    {
        if (s <= 0)
        {
            cout << "Invalid size. Using default size " << MAX_SIZE << endl;
            size = MAX_SIZE;
        }
        else
            size = s;

        numbers = new double[size];
        for (int i = 0; i < size; i++)
            numbers[i] = 0.0;

        cout << "Array of size " << size << " created." << endl;
    }

    // Destructor
    ~NumberArray()
    {
        delete[] numbers;
        cout << "The destructor is running" << endl;
    }

    // Mutator: store number at given index
    void setNumber(int index, double value)
    {
        if (index < 0 || index >= size)
        {
            cout << "The index is out of the bounds of the array, number not stored" << endl;
            return;
        }
        numbers[index] = value;
    }

    // Accessor: retrieve number from given index
    double getNumber(int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "The Index is out of the bounds of the array, returning default" << endl;
            return DEFAULT_VALUE;
        }
        return numbers[index];
    }

    // Return highest value
    double getHighest() const
    {
        double highest = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] > highest)
                highest = numbers[i];
        return highest;
    }

    // Return lowest value
    double getLowest() const
    {
        double lowest = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] < lowest)
                lowest = numbers[i];
        return lowest;
    }

    // Return average of values
    double getAverage() const
    {
        double total = 0;
        for (int i = 0; i < size; i++)
            total += numbers[i];
        return total / size;
    }

    // Print all array values
    void print() const
    {
        cout << fixed << setprecision(1);
        for (int i = 0; i < size; i++)
            cout << numbers[i] << " ";
        cout << endl;
    }
};

// Initialize static constant
const double NumberArray::DEFAULT_VALUE = 10000.0;

// ===============================
//          MAIN FUNCTION
// ===============================
int main()
{
    cout << "----- Test constructors -----" << endl;

    // Default constructor
    NumberArray arr1;
    cout << "From default constructor: Array of size 10" << endl;
    arr1.print();

    // Constructor with parameters
    NumberArray arr2(15);
    cout << "From constructor with parameters: Array of size 15" << endl;
    arr2.print();

    cout << "----- Test mutator -----" << endl;

    // Use random numbers to fill array
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1.0, 100.0);

    for (int i = 0; i < 15; i++)
    {
        double val = dist(gen);
        arr2.setNumber(i, val);
    }

    cout << "Array filled with numbers:" << endl;
    arr2.print();

    cout << "Trying to set a number with an out of bounds index (20):" << endl;
    arr2.setNumber(20, 55.5);

    cout << "----- Test accessors -----" << endl;

    cout << "Access item at index 5: " << arr2.getNumber(5) << endl;

    cout << "Access item at index 20 (out of bounds): " << arr2.getNumber(20) << endl;

    cout << "The minimum value in the array is: " << arr2.getLowest() << endl;
    cout << "The maximum value in the array is: " << arr2.getHighest() << endl;
    cout << "The average of the values in the array is: " << arr2.getAverage() << endl;

    return 0;
}