/**********|**********|**********|
Program: GenericRobot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "GenericRobot.h"
#include "../misc/battleground.h"
#include "../misc/randomizer.h"



GenericRobot::GenericRobot(std::string name, std::string type, std::string letter, int xPos, int yPos)
    : Robot(name, type, letter, xPos, yPos),
      MovingRobot(name, type, letter, xPos, yPos),
      SeeingRobot(name, type, letter, xPos, yPos),
      ShootingRobot(name, type, letter, xPos, yPos),
      ThinkingRobot(name, type, letter, xPos, yPos)
{
}


void GenericRobot::executeAction(Battleground& field, std::vector<std::string>& actionLog)
{
    look(0, 0, field, actionLog);       // looks around itself (temporary)
    int dx = Randomizer::generateRandom(-1, 1);
    int dy = Randomizer::generateRandom(-1, 1);

    int targetX = getXPos() + dx;
    int targetY = getYPos() + dy;

    move(targetX, targetY, field, actionLog);


    fire(dx, dy, field, actionLog);
}