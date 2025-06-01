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
           moveUpgradeID(0), shootUpgradeID(0), seeUpgradeID(0),
           fired(false), looked(false), moved(false)
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

        if (moveChoice == 1) 
        {
            upgradeName = "HideBot";
            setHideCount(3);
        }

        else if (moveChoice == 2)
        {
            upgradeName = "JumpBot";
            setJumpCount(3);
        } 

        else if (moveChoice == 3) upgradeName = "CrushBot";
    }

    else if (chosenArea == "shooting") 
    {
        // 1 = LongShotBot, 2 = SemiAutoBot, 3 = ThirtyShotBot, 4 = AccuracyBot
        int shootChoice = Randomizer::generateRandom(1, 3);
        shootUpgradeID = shootChoice;

        if (shootChoice == 1) upgradeName = "LongShotBot";
        else if (shootChoice == 2) 
        {
            upgradeName = "SemiAutoBot";
            availableUpgradeAreas.push_back("shootingTier2");
        }
        else if (shootChoice == 3)
        {
            upgradeName = "ThirtyShotBot";
            setShells(30);
        }
    }

    else if (chosenArea == "seeing")
    {
        // 1 = ScoutBot, 2 = TrackBot
        int seeChoice = Randomizer::generateRandom(1, 2);
        seeUpgradeID = seeChoice;
        
        if (seeChoice == 1) 
        {
            upgradeName = "ScoutBot";
            setScoutCount(3);
        }
        else if (seeChoice == 2) 
        {
            upgradeName = "TrackBot";
            setTrackCount(3);
        }
    }

    else if (chosenArea == "healing")
    {
        upgradeName = "Heal One Life";
        lives++;
    }

    else if (chosenArea == "shootingTier2")
    {
        shootUpgradeID = 4;
        upgradeName = "AccuracyBot";
        setAccuracy(100);
    }

    availableUpgradeAreas.erase(availableUpgradeAreas.begin() + upgradeAreaIndex);

    actionLog.push_back(getName() + " (" + getLetter() + ") chose the " + upgradeName + " upgrade!");
    // note to self: im pretty proud of myself for this one LOL i hope it works UPDATE: IT WORKS SO FREAKING WELL IM SO HAPPY

}

int Robot::getAccuracy() const
{
    return accuracy;
}

void Robot::setAccuracy(int newAccuracy)
{
    accuracy = newAccuracy;
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
    return hideCount;
}

void Robot::setHideCount(int newHideCount)
{
    hideCount = newHideCount;
}

int Robot::getJumpCount() const
{
    return jumpCount;
}

void Robot::setJumpCount(int newJumpCount)
{
    jumpCount = newJumpCount;
}

int Robot::getScoutCount() const
{
    return scoutCount;
}

void Robot::setScoutCount(int newScoutCount)
{
    scoutCount = newScoutCount;
}

void Robot::track(Robot* target, std::vector<std::string>& actionLog)
{
    if (seeUpgradeID == 2 && trackCount > 0 && target != this)
    {
        trackedRobots.push_back(target);
        
        actionLog.push_back(getName() + " (" + getLetter() + ") planted a tracker on " + target->getName() + " (" + target->getLetter() + ")!");

        // IDK IF I HAVE TIME TO FIGURE OUT THE LOGIC BEHIND THIS
        trackCount--;

        target->setTracked(true);
    }
}

void Robot::setTracked(bool newTracked)
{
    tracked = newTracked;
}

const std::vector<Robot*>& Robot::getTrackedRobots() const 
{
    return trackedRobots;
}

int Robot::getTrackCount() const
{
    return trackCount;
}

void Robot::setTrackCount(int newTrackCount)
{
    trackCount = newTrackCount;
}

bool Robot::getMoved() const
{
    return moved;
}

void Robot::setMoved(bool newMoved)
{
    moved = newMoved;
}

bool Robot::getFired() const
{
    return fired;
}

void Robot::setFired(bool newFired)
{
    fired = newFired;
}
