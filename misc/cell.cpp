/**********|**********|**********|
Program: cell.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/



#include "cell.h"



Cell::Cell(int x, int y) : x(x), y(y) 
{
}

int Cell::getX() const
{
    return x;
}

int Cell::getY() const
{
    return y;
}

std::string Cell::getChar() const
{
    return robot ? robot->getChar() : " ";
}

void Cell::placeRobot(Robot* robot)
{
    this->robot = robot;
}

void Cell::removeRobot()            // technically placeRobot can do the same thing,
{                                   // but it's more readable and intuitive this way
    robot = nullptr;
}

bool Cell::hasRobot() const
{
    return robot != nullptr;        // returns true if it's not nullptr (meaning there is a robot)
}

Robot* Cell::getRobot() const
{
    return robot;
}
