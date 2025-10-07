/*
File Name: ReverseArray.cpp
Author: Bramesh Patel
Date: 10/06/2025

Description:
This program allows the user to create an array of any size and fill it with
their own numbers. It then sorts the array in increasing order and displays
the result, followed by sorting it in decreasing order and displaying that
as well. The program demonstrates dynamic memory allocation, user input,
and sorting with simple loops.
*/

#include <iostream>
using namespace std;

/*
Function: print
Input: A constant integer array and its size.
Precondition: The array must contain valid integers.
Postcondition: Displays all elements of the array separated by spaces.
*/
void print(int const arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
Function: sortAscending
Input: Integer array and its size.
Precondition: The array must contain valid integers.
Postcondition: Rearranges the array elements in increasing order.
*/
void sortAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
Function: sortDescending
Input: Integer array and its size.
Precondition: The array must contain valid integers.
Postcondition: Rearranges the array elements in decreasing order.
*/
void sortDescending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int size;

    cout << "Enter the number of elements you want in the array: ";
    cin >> size;

    // Dynamically allocate an array of user-defined size
    int *numbers = new int[size];

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nOriginal array:" << endl;
    print(numbers, size);

    // Sort and display in increasing order
    sortAscending(numbers, size);
    cout << "\nArray in increasing order:" << endl;
    print(numbers, size);

    // Sort and display in decreasing order
    sortDescending(numbers, size);
    cout << "\nArray in decreasing order:" << endl;
    print(numbers, size);

    // Free memory
    delete[] numbers;

    return 0;
}
