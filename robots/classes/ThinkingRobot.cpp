/**********|**********|**********|
Program: ThinkingRobot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/



#include "ThinkingRobot.h"
#include "../../misc/randomizer.h"



Robot* ThinkingRobot::findEnemy(const Battleground& field)
{
    int minDist = 999999;
    Robot* closest = nullptr;
    
    for (Robot* other : field.robots) 
    {
        if (other == this || !other->isAlive()) continue;

        int dist = std::abs(getXPos() - other->getXPos()) + std::abs(getYPos() - other->getYPos());

        if (dist < minDist) 
        {
            minDist = dist;
            closest = other;
        }
    }
    return closest;
}