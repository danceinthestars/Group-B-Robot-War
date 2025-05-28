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




GenericRobot::GenericRobot(std::string name, std::string type, std::string letter, int xPos, int yPos)
    : Robot(name, type, letter, xPos, yPos),
      MovingRobot(name, type, letter, xPos, yPos),
      SeeingRobot(name, type, letter, xPos, yPos),
      ShootingRobot(name, type, letter, xPos, yPos),
      ThinkingRobot(name, type, letter, xPos, yPos)
{
}


void GenericRobot::executeAction()
{
    // Decide what this robot does on its turn.
    // For example, you could call move(), look(), shoot(), or think() here
}