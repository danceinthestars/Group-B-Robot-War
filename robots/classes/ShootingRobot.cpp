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
    if (shells > 0) 
    {
        // a robot shouldn't be able to shoot at itself, but if it SOMEHOW manages to, i thought this would be funny LMAO
        if (dx == 0 && dy == 0) 
        {
            actionLog.push_back(getName() + " (" + getLetter() + ") tried to break the Third Law of Robotics and attempted to shoot itself. You can't do that in this game.");
            return;
        }


        int targetX = getXPos() + dx;
        int targetY = getYPos() + dy;

        // shouldn't happen if i code its algorithm right, but just in case
        if (targetX < 0 || targetX >= field.getRows() || targetY < 0 || targetY >= field.getCols()) 
        {
            actionLog.push_back(getName() + " (" + getLetter() + ") tried to fire out of bounds.");
            return;
        }

        // 70% chance to hit
        int hitChance = Randomizer::generateRandom(0, 100);

        if (hitChance <= 70) 
        {
            Cell* targetCell = field.getCell(targetX, targetY);

            if (targetCell && targetCell->hasRobot()) 
            {
                Robot* target = targetCell->getRobot();
    
                actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" + std::to_string(targetX) + ", " + std::to_string(targetY) + ") and HIT " + target->getName() + " (" + target->getLetter() + ")!");

                field.killRobot(this, target);

            } 
            
            else // robot targets a cell that's empty
            {                         
                actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" + std::to_string(targetX) + ", " + std::to_string(targetY) + ") but hit nothing.");
            }
        } 
        
        else 
        {                              // robot misses (regardless of aiming at another robot or empty cell)
            actionLog.push_back(getName() + " (" + getLetter() + ") fired at (" + std::to_string(targetX) + ", " + std::to_string(targetY) + ") and MISSED.");
        }
        
        // deduct shell after successful fire
        shells--;
    }

    // out of shells = self-destruct   o7 (edit: i realise that if it survives selfdestruction it can still fire into the negatives but uh.. hopefully that dont happen once i finish this)
    if (shells <= 0) 
    {
        actionLog.push_back(getName() + " (" + getLetter() + ") has run out of shells and will self-destruct!");

        field.selfDestruct(this); 

    }

    // increment kills; if kills <= 3, upgrade robot?
    // 

}