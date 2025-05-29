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

    // if it moves to the same coords its already in, just do nothing lol
    if (newX == getXPos() && newY == getYPos()) {
        return;
    }

    // if a robot somehow tries to move more than 1 cell at a time
    if (dx > 1 || dy > 1) {
        actionLog.push_back(getName() + " (" + getLetter() + ") thought it was a JumpBot and tried to jump to (" +
                            std::to_string(newX) + ", " + std::to_string(newY) + "), but fails.");
        return;
    }

    // for if a robot tries to move out of bounds
    if (newX < 0 || newX >= field.getRows() || newY < 0 || newY >= field.getCols()) {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to move out of the map to (" +
                            std::to_string(newX) + ", " + std::to_string(newY) + ")");
        return;
    }

    // for if a robot tries to move into an occupied cell
    Cell* dest = field.getCell(newX, newY);
    if (dest->hasRobot()) {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to move to (" +
                            std::to_string(newX) + ", " + std::to_string(newY) + ") but got blocked.");
        return;
    }

    // remove robot from current cell
    Cell* current = field.getCell(getXPos(), getYPos());
    if (current) current->removeRobot();

    // place robot in new cell
    dest->placeRobot(this);

    xPos = newX;
    yPos = newY;

    actionLog.push_back(getName() + " (" + getLetter() + ") moved to (" +
                        std::to_string(newX) + ", " + std::to_string(newY) + ")");
}