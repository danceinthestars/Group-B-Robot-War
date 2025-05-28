/**********|**********|**********|
Program: robot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "robot.h"

#include <string>
#include <memory>

Robot::Robot(std::string name, std::string type, std::string letter, int xPos, int yPos)
           : name(name), type(type), letter(letter), xPos(xPos), yPos(yPos), lives(3), kills(0)
{

}

std::string Robot::getName() const
{
    return std::string();
}

std::string Robot::getType() const
{
    return std::string();
}

std::string Robot::getLetter() const
{
    return letter;
}

int Robot::getXPos() const
{
    return 0;
}

int Robot::getYPos() const
{
    return 0;
}

int Robot::getLives() const
{
    return 0;
}

int Robot::getKills() const
{
    return 0;
}

bool Robot::isTracked() const
{
    return false;
}
