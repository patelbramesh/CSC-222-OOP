/*
File Name: ReverseArray.cpp
Author: Bramesh Patel
Date: 10/06/2025

Description:
This program demonstrates dynamic memory allocation, array manipulation,
and passing arrays as function parameters. It first creates and displays
an array of integers, then calls a function that dynamically allocates
a new array to store the numbers in reverse order. Finally, it displays
the reversed array and properly deallocates memory before the program ends.
*/

#include <iostream>
using namespace std;

/*
Function Name: ReverseArray
----------------------------------------------------------
Input:
 - arr: a constant integer array passed by pointer (read-only)
 - size: the number of elements in the array

Precondition:
 - The array must contain valid integer elements.
 - The size parameter must be greater than zero.

Postcondition:
 - Dynamically allocates a new integer array of the same size.
 - Copies elements from the original array in reverse order.
 - Returns a pointer to the newly created reversed array.
 - The caller is responsible for deleting the allocated memory.
*/
int *ReverseArray(int const arr[], int size)
{
    // Dynamically create a new array of the same size
    int *revArr = new int[size];

    // Copy elements from original array in reverse order
    for (int i = 0; i < size; i++)
    {
        revArr[i] = arr[size - 1 - i];
    }

    return revArr; // Return pointer to reversed array
}

/*
Function Name: print
Input:
 - arr: a constant integer array (read-only)
 - size: the number of elements in the array

Precondition:
 - The array must contain valid data.
 - The size must be greater than zero.

Postcondition:
 - Displays all elements of the array in a clean format.
*/
void print(int const arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Allocate memory at runtime for the array size based on program input
    const int SIZE = 10;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array:" << endl;
    print(numbers, SIZE);

    // Call ReverseArray to create a new reversed array
    int *reversed = ReverseArray(numbers, SIZE);

    cout << "Reversed array:" << endl;
    print(reversed, SIZE);

    // Correctly deallocate memory to prevent leaks
    delete[] reversed;

    // Program terminates successfully
    return 0;
}