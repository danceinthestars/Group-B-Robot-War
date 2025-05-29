/**********|**********|**********|
Program: ShootingRobot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "ShootingRobot.h"
#include "../../misc/battleground.h"
#include "../../misc/cell.h"
#include "../../misc/randomizer.h"



void ShootingRobot::fire(int dx, int dy, Battleground& field, std::vector<std::string>& actionLog)
{
    // a robot shouldn't be able to shoot at itself, but if it SOMEHOW manages to, i thought this would be funny LMAO
    if (dx == 0 && dy == 0) {
        actionLog.push_back(getName() + " (" + getLetter() + 
        ") tried to break the Third Law of Robotics and attempted to shoot itself. You can't do that in this game.");
        return;
    }

    // only accepts parameters that are adjacent to the robot's location
    if (std::abs(dx) > 1 || std::abs(dy) > 1) {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to fire out of range at (" +
                            std::to_string(getXPos() + dx) + ", " + std::to_string(getYPos() + dy) + ")");
        return;
    }

    // if shells are empty, can't shoot; though this shouldn't happen since robots self-destruct if out of shells
    if (shells <= 0) {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to fire but is out of shells!");
        return;
    }

    int targetX = getXPos() + dx;
    int targetY = getYPos() + dy;

    // shouldn't happen if i code its algorithm right, but just in case
    if (targetX < 0 || targetX >= field.getRows() || targetY < 0 || targetY >= field.getCols()) {
        actionLog.push_back(getName() + " (" + getLetter() + ") tried to fire out of the map at (" +
                            std::to_string(targetX) + ", " + std::to_string(targetY) + ")");
        return;
    }

    // now that all fail scenarios are out of the way, lower shells by one
    shells--;

    // 70% chance to hit
    int hitChance = Randomizer::generateRandom(1, 100);
    if (hitChance <= 70) {
        Cell* targetCell = field.getCell(targetX, targetY);
        if (targetCell && targetCell->hasRobot()) {
            Robot* target = targetCell->getRobot();
            if (target != this) {
                actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" +
                                    std::to_string(targetX) + ", " + std::to_string(targetY) +
                                    ") and HIT " + target->getName() + " (" + target->getLetter() + ")!");
                // field.killRobot(target); // Call this when implemented
            } 
            
            else {
                // Should never happen due to earlier check, but just in case
                actionLog.push_back(getName() + " (" + getLetter() + ") tried to commit suicide! Action ignored.");
            }

        } 
        
        else {
            actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" +
                                std::to_string(targetX) + ", " + std::to_string(targetY) + ") but hit nothing.");
        }
    } 
    
    else {
        actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" +
                            std::to_string(targetX) + ", " + std::to_string(targetY) + ") and MISSED.");
    }
}