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

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "cell.h"

// To-Do List:
// implement cells 
// 


class Battleground {
    private:

    int rows;
    int cols;
    int maxSteps;
    int currentStep;


    std::vector<std::vector<Cell*>> grid;


    std::string displayBattleground();


    public:
    Battleground(int rows, int cols, int maxSteps);
};