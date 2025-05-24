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



int main()
{
    int rows = 20;
    int cols = 20;
    int maxSteps = 5;

    Battleground field(rows, cols, maxSteps);

    std::string fieldString = field.displayBattleground();
    std::cout << fieldString;

    std::cout << "test";

    while(true)
    {
        int input;
        std::cin >> input;   // just so i can see the output
    }
}