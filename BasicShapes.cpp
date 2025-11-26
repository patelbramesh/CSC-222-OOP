/*
File Name: BasicShapes.cpp
Author: Bramesh Patel
Date: 11/26/2025

Description:
This program demonstrates inheritance using an abstract base
class called BasicShape and derived classes Circle, Rectangle,
and Square. An array of BasicShape pointers is used to display
each shape's name and area.
*/

#include <iostream>
#include "BasicShape.h"
using namespace std;

// ===============================
//           MAIN FUNCTION
// ===============================
int main()
{
    // Array of 5 BasicShape pointers
    BasicShape* shapes[5];

    // Two Rectangle objects
    shapes[0] = new Rectangle(4.0, 6.0, "Office Rectangle");
    shapes[1] = new Rectangle(10.0, 3.5, "Hallway Rectangle");

    // Two Circle objects
    shapes[2] = new Circle(0.0, 0.0, 5.0, "Large Circle");
    shapes[3] = new Circle(2.0, 3.0, 2.5, "Small Circle");

    // One Square object
    shapes[4] = new Square(4.0, "Perfect Square");

    // Display shape names and areas
    cout << "\n----- Shape Information -----\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Shape: " << shapes[i]->getName() << endl;
        cout << "Area : " << shapes[i]->getArea() << endl;
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < 5; i++)
        delete shapes[i];

    return 0;
}