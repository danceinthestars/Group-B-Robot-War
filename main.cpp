/**********|**********|**********|
Program: main.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include <iostream>
#include <memory>

#include "misc/battleground.h"
#include "robots/GenericRobot.h"



int main()
{
    int rows = 10;
    int cols = 10;
    int maxSteps = 2;

    Battleground field(rows, cols, maxSteps);



    std::cout << "Welcome to Robot War Simulator! Press Enter to start!" << std::endl;

    field.runGame();
}