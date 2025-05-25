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