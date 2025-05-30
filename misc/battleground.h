/**********|**********|**********|
Program: battleground.h
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
#include <memory>


#include "cell.h"


class Battleground 
{
    private:

    int rows;
    int cols;
    int maxSteps;
    int currentStep;


    std::vector<std::vector<std::unique_ptr<Cell>>> grid;


    


    public:
    Battleground(int rows, int cols, int maxSteps);         // constructor
    std::string displayBattleground();                      // display the battleground as a string

    int getRows() const;                                    // get total number of rows in the battleground

    int getCols() const;                                    // get total number of columns in the battleground

    int getMaxSteps() const;

    int getCurrentStep() const;

    Cell* getCell(int x, int y) const;                      // get coordinates of a cell

    void addRobot(Robot* robot, int x, int y);              // add a robot to the battleground

    void selfDestruct(Robot* robot);

    void killRobot(Robot* killer, Robot* target);

    void runGame();

    void respawnRobot();

    std::vector<Robot*> robots;                             // list of robots
    std::vector<std::string> actionLog;                     // log of actions that happen during a round
    std::vector<Robot*> respawnQueue;                       // queue for robots who need to respawn
};