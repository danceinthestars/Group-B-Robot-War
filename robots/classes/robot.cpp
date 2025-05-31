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
#include "../../misc/randomizer.h"


#include <vector>
#include <string>
#include <memory>

Robot::Robot(std::string name, std::string type, std::string letter, int xPos, int yPos)
           : name(name), type(type), letter(letter), xPos(xPos), yPos(yPos), 
           lives(3), accuracy(70), shells(10), 
           alive(true), //upgradeCount(0),
           moveUpgradeID(0), shootUpgradeID(0), seeUpgradeID(0)
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

//int Robot::getUpgradeCount() const
//{
//    return upgradeCount;
//}

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

//void Robot::setUpgradeCount(int newUpgradeCount)
//{
//    upgradeCount = newUpgradeCount;
//}

void Robot::setAlive(bool newStatus)
{
    alive = newStatus;
}

void Robot::setXPos(int newX)
{
    xPos = newX;
}

void Robot::setYPos(int newY)
{
    yPos = newY;
}

void Robot::setShells(int newShells)
{
    shells = newShells;
}

void Robot::upgrade(std::vector<std::string>& actionLog) {
    
    if (availableUpgradeAreas.empty())
    {
        return;
    }

    // this generates a number from 0 to the list's size (minused by 1, you'll see why)
    // for example, (0, [3-1=2]) generates either 0 (moving), 1 (shooting) or 2 (seeing)
    int upgradeAreaIndex = Randomizer::generateRandom(0, static_cast<int>(availableUpgradeAreas.size() - 1));
    std::string chosenArea = availableUpgradeAreas[upgradeAreaIndex];
    std::string upgradeName;

    // these next ones, we randomise starting from 1, as 0 means it hasn't upgraded there

    // note to self: remember to change random parameters once i add the new types
    if (chosenArea == "moving")
    {
        // 1 = Hidebot, 2 = JumpBot, 3 = CrushBot
        int moveChoice = Randomizer::generateRandom(1, 3);
        moveUpgradeID = moveChoice;

        if (moveChoice == 1) upgradeName = "HideBot";
        else if (moveChoice == 2) upgradeName = "JumpBot";
        else if (moveChoice == 3) upgradeName = "CrushBot";
    }

    else if (chosenArea == "shooting") 
    {
        // 1 = LongShotBot, 2 = SemiAutoBot, 3 = ThirtyShotBot, 4 = AccuracyBot
        int shootChoice = Randomizer::generateRandom(1, 4);
        shootUpgradeID = shootChoice;

        if (shootChoice == 1) upgradeName = "LongShotBot";
        else if (shootChoice == 2) upgradeName = "SemiAutoBot";
        else if (shootChoice == 3) upgradeName = "ThirtyShotBot";
        else if (shootChoice == 4) upgradeName = "AccuracyBot";
    }

    else if (chosenArea == "seeing")
    {
        // 1 = ScoutBot, 2 = TrackBot
        int seeChoice = Randomizer::generateRandom(1, 2);
        seeUpgradeID = seeChoice;
        
        if (seeChoice == 1) upgradeName = "ScoutBot";
        else if (seeChoice == 2) upgradeName = "TrackBot";
    }

    availableUpgradeAreas.erase(availableUpgradeAreas.begin() + upgradeAreaIndex);

    actionLog.push_back(getName() + " (" + getLetter() + ") chose the " + upgradeName + " upgrade!");
    // note to self: im pretty proud of myself for this one LOL i hope it works

}

int Robot::getAccuracy() const
{
    return accuracy;
}

void Robot::hide()
{
    if (moveUpgradeID==1 && hideCount > 0 && !isHidden)
    {
        isHidden = true;
        hideCount--;
    }
}

bool Robot::getHidden() const
{
    return isHidden;
}

void Robot::setHidden(bool newHidden)
{
    isHidden = newHidden;
}

int Robot::getHideCount() const
{

}

void Robot::setHideCount(int newHideCount)
{

}

void Robot::jump()
{

}

int Robot::getJumpCount() const
{

}

void Robot::setJumpCount(int newJumpCount)
{

}

void Robot::scout()
{

}

int Robot::getScoutCount() const
{

}

void Robot::setScoutCount(int newScoutCount)
{

}

void Robot::track()
{

}

int Robot::getTrackCount() const
{

}

void Robot::setTrackCount(int newTrackCount)
{

}