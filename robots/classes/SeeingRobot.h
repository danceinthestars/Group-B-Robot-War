/**********|**********|**********|
Program: SeeingRobot.h
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



class SeeingRobot : virtual public Robot
{
    using Robot::Robot;

    public:
    virtual std::vector<std::vector<std::string>> look(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog) const;

    virtual std::vector<std::vector<std::string>> scout(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog);

    virtual std::vector<std::vector<std::string>> receiveTrackedPositions(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog) const;
};

