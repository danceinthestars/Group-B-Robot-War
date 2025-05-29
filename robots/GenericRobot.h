/**********|**********|**********|
Program: GenericRobot.h
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

#include "classes/MovingRobot.h"
#include "classes/SeeingRobot.h"
#include "classes/ShootingRobot.h"
#include "classes/ThinkingRobot.h"



class GenericRobot : public MovingRobot, public SeeingRobot, public ShootingRobot, public ThinkingRobot
{
    public:
    GenericRobot(std::string name, std::string type, std::string letter, int xPos, int yPos);

    void executeAction(Battleground& field, std::vector<std::string>& actionLog) override;
};