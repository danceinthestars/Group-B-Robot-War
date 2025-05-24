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
    return " ";
}
