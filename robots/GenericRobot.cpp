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
#include "classes/robot.h"



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
    look(0, 0, field, actionLog);

    if (moveUpgradeID == 1 && getHideCount() > 0 && !getHidden()) 
    {
        hide();
        actionLog.push_back(getName() + " (" + getLetter() + ") hid from the battleground! Enemies cannot target it!");
        return;
    }

    scout(0, 0, field, actionLog); // scout whenever possible, might add random chance of using this if i have time
                                   // no need to check id cuz it does it in the function already

    Robot* target = findEnemy(field);


    // track if an enemy hasn't been tracked by anyone yet
    // no need to run range checkers cuz look() can only see whatever's in range anyway and if its a trackbot it doesnt have other see upgrades
    if (seeUpgradeID == 2 && getTrackCount() > 0 && target && !target->isTracked()) 
    {
        track(target, actionLog);
        return;
    }

    receiveTrackedPositions(0, 0, field, actionLog);

    int dx = 0;
    int dy = 0;
    target = findEnemy(field);
    if (target)
    {
        dx = target->getXPos() - getXPos();
        dy = target->getYPos() - getYPos();
    }



    // jump mechanics
    if (moveUpgradeID == 2 && getJumpCount() > 0 && target) 
    {
        if (std::abs(dx) > 1 || std::abs(dy) > 1) 
        {
            int jumpX = getXPos() + (dx != 0 ? (dx > 0 ? 2 : -2) : 0);
            int jumpY = getYPos() + (dy != 0 ? (dy > 0 ? 2 : -2) : 0);

            move(jumpX, jumpY, field, actionLog);
            // does not make moved = true here cause jump is a separate action

            return;
        }
    }

    // crushbot
    if (moveUpgradeID == 3 && target) 
    {
        if (std::abs(dx) + std::abs(dy) == 1) 
        {
            move(target->getXPos(), target->getYPos(), field, actionLog);
            setMoved(true);
            return;
        }
    }

    // longshotbot
    if (shootUpgradeID == 1 && target) 
    {
        if (std::abs(dx) + std::abs(dy) <= 3 && getShells() > 0) 
        {
            fire(dx, dy, field, actionLog);
            setFired(true);
            return;
        }
    }

    // misc
    if (target) 
    {
        if (std::abs(dx) + std::abs(dy) > 1) 
        {
            if (!getMoved()) 
            {
                int stepX = getXPos() + (dx != 0 ? (dx > 0 ? 1 : -1) : 0);
                int stepY = getYPos() + (dy != 0 ? (dy > 0 ? 1 : -1) : 0);
                move(stepX, stepY, field, actionLog);
                setMoved(true);

                if (!getFired())
                {
                    fire(dx, dy, field, actionLog);
                    setFired(true);
                }
            }
        }

        else 
        {
            if (!getFired())
            {
                fire(dx, dy, field, actionLog);
                setFired(true);
            }

        }

    } 
    else 
    {
        if (!(getMoved()))
        {
        // can't find enemies? move around i dunno
        int moveX = getXPos() + Randomizer::generateRandom(-1, 1);
        int moveY = getYPos() + Randomizer::generateRandom(-1, 1);
        move(moveX, moveY, field, actionLog);
        }

    }
}