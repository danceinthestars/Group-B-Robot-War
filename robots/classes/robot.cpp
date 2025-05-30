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
           : name(name), type(type), letter(letter), xPos(xPos), yPos(yPos), lives(3), kills(0), shells(10), alive(true)
{

}

std::string Robot::getName() const
{
    return name;
}

std::string Robot::getType() const
{
    return type;
}

std::string Robot::getLetter() const
{
    return letter;
}

int Robot::getXPos() const
{
    return xPos;
}

int Robot::getYPos() const
{
    return yPos;
}

int Robot::getLives() const
{
    return lives;
}

int Robot::getKills() const
{
    return kills;
}

int Robot::getShells() const
{
    return shells;
}

bool Robot::isTracked() const
{
    return false;   // change this once TrackBot is implemented
}

void Robot::setLives(int newLives)
{
    lives = newLives;
}

bool Robot::isAlive() const
{
    return alive;
}

void Robot::setKills(int newKills)
{
    kills = newKills;
}

void Robot::setAlive(bool status)
{
    alive = status;
}