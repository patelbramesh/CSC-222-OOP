#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class NumberArray
{
private:
    T* numbers;   // pointer to dynamic array
    int size;     // array size

public:
    static const int MAX_SIZE = 10;

    // ---------------------------------------------------
    // Constructor (default or sized)
    // ---------------------------------------------------
    NumberArray(int s = MAX_SIZE)
    {
        size = s;
        numbers = new T[size];
        for (int i = 0; i < size; i++)
            numbers[i] = T();  // default initialize
    }

    // ---------------------------------------------------
    // Destructor
    // ---------------------------------------------------
    ~NumberArray()
    {
        cout << "The destructor is running\n";
        delete[] numbers;
    }

    // ---------------------------------------------------
    // Mutator (throws out_of_range)
    // ---------------------------------------------------
    void setNumber(int index, T value)
    {
        if (index < 0 || index >= size)
            throw out_of_range("The index is out of the bounds of the array, number not stored");
        numbers[index] = value;
    }

    // ---------------------------------------------------
    // Accessor (throws out_of_range)
    // ---------------------------------------------------
    T getNumber(int index) const
    {
        if (index < 0 || index >= size)
            throw out_of_range("The index is out of the bounds of the array, number not stored");
        return numbers[index];
    }

    // ---------------------------------------------------
    // Return highest value
    // ---------------------------------------------------
    T getHighest() const
    {
        T maxVal = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] > maxVal)
                maxVal = numbers[i];
        return maxVal;
    }

    // ---------------------------------------------------
    // Return lowest value
    // ---------------------------------------------------
    T getLowest() const
    {
        T minVal = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] < minVal)
                minVal = numbers[i];
        return minVal;
    }

    // ---------------------------------------------------
    // Return average
    // ---------------------------------------------------
    double getAverage() const
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += numbers[i];
        return sum / size;
    }

    // ---------------------------------------------------
    // Print array contents
    // ---------------------------------------------------
    void print() const
    {
        for (int i = 0; i < size; i++)
            cout << numbers[i] << " ";
        cout << endl;
    }

    // ---------------------------------------------------
    // Getter for size
    // ---------------------------------------------------
    int getSize() const { return size; }
};

#endif