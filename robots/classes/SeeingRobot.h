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
    // (dx, dy) is the coords, field is the map, actionLog is the log
    // idk why i need to write parameters like this but it works and i dont have time to change it to be more coherent
    virtual std::vector<std::vector<std::string>> look(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog) const;

    
};

