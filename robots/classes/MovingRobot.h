/**********|**********|**********|
Program: MovingRobot.h
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

#include "robot.h"
#include "../../misc/battleground.h"

#include <vector>
#include <string>



class MovingRobot : virtual public Robot
{
    using Robot::Robot;

    public:
    virtual void move(int newX, int newY, Battleground& field, std::vector<std::string>& actionLog);
};