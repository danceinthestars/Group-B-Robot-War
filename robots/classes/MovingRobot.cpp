/**********|**********|**********|
Program: MovingRobot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "MovingRobot.h"
#include "../../misc/battleground.h"
#include "../../misc/cell.h"



void MovingRobot::move(int newX, int newY, Battleground& field, std::vector<std::string>& actionLog)
{
    int dx = std::abs(newX - getXPos());
    int dy = std::abs(newY - getYPos());

    Cell* dest = field.getCell(newX, newY);

    // if it moves to the same coords its already in, just do nothing lol
    if (newX == getXPos() && newY == getYPos()) 
    {
        return;
    }

    // for if a robot tries to move out of bounds
    if (newX < 0 || newX >= field.getRows() || newY < 0 || newY >= field.getCols()) 
    {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to move out of the map to (" + std::to_string(newX) + ", " + std::to_string(newY) + ")");
        return;
    }

    // if a robot tries to move more than 1 cell away, check if it's a jumpbot
    if (dx > 1 || dy > 1) 
    {
        if (moveUpgradeID == 2 && jumpCount > 0)
        {
            if (dest->hasRobot())   // im repeating code from below i know its bad but im out of time to be clever
            {
                actionLog.push_back(getName() + " (" + getLetter() + ") tried to move to (" + std::to_string(newX) + ", " + std::to_string(newY) + ") but got blocked.");
                return;
            }
        
        moveRobot(newX, newY, field);

        actionLog.push_back(getName() + " (" + getLetter() + ") jumped to (" + std::to_string(newX) + ", " + std::to_string(newY) + ")!");
        jumpCount--;

        return;
        }

        else
        {
        actionLog.push_back(getName() + " (" + getLetter() + ") thought it was a JumpBot and tried to jump to (" + std::to_string(newX) + ", " + std::to_string(newY) + "), but fails.");
        return;
        }

    }


    // for if a robot tries to move into an occupied cell
    if (dest->hasRobot()) 
    {
        if (moveUpgradeID == 3) {
            field.killRobot(this, dest->getRobot());
            moveRobot(newX, newY, field);

            actionLog.push_back(getName() + " (" + getLetter() + ") moved to (" + std::to_string(newX) + ", " + std::to_string(newY) + ") and crushed an enemy!");
        }

        else
        {
            actionLog.push_back(getName() + " (" + getLetter() + ") tried to move to (" + std::to_string(newX) + ", " + std::to_string(newY) + ") but got blocked.");
            return;
        }

    }

    moveRobot(newX, newY, field);

    actionLog.push_back(getName() + " (" + getLetter() + ") moved to (" + std::to_string(newX) + ", " + std::to_string(newY) + ").");
}



void MovingRobot::moveRobot(int newX, int newY, Battleground& field)
{
    Cell* dest = field.getCell(newX, newY);

    Cell* current = field.getCell(getXPos(), getYPos());
    if (current) current->removeRobot();

    dest->placeRobot(this);

    xPos = newX;
    yPos = newY;
}