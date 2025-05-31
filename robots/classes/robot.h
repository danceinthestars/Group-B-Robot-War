/**********|**********|**********|
Program: robot.h
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#pragma once

#include <string>
#include <memory>
#include <vector>

class Battleground;

class Robot {
    protected:
    std::string name;
    std::string type;
    std::string letter;
    int xPos;
    int yPos;
    int lives;
    int accuracy;
    int shells;
    bool alive;
    //int upgradeCount;

    // 1 = Hidebot, 2 = JumpBot, 3 = CrushBot
    int moveUpgradeID;      
    // 1 = LongShotBot, 2 = SemiAutoBot, 3 = ThirtyShotBot, 4 = AccuracyBot
    int shootUpgradeID; 
    // 1 = ScoutBot, 2 = TrackBot
    int seeUpgradeID;     
    
    std::vector<std::string> availableUpgradeAreas = {"moving", "shooting", "seeing"}; // they're long names but they're apt ok

    private:

    public:
    Robot(std::string name, std::string type, std::string letter, int xPos, int yPos);

    virtual ~Robot() = default;

    std::string getName() const;

    std::string getType() const;

    std::string getLetter() const;

    int getXPos() const;

    int getYPos() const;

    int getLives() const;

    //int getUpgradeCount() const;

    int getShells() const;

    bool isAlive() const;

    bool isTracked() const;             // for TrackBot

    virtual void executeAction(Battleground& field, std::vector<std::string>& actionLog) = 0;

    void setLives(int newLives);

    //void setUpgradeCount(int newUpgradeCount);

    void setAlive(bool newStatus);

    void setXPos(int newX);        // mfw completely forgot to add this

    void setYPos(int newY);

    void setShells(int newShells);

    void upgrade(std::vector<std::string>& actionLog);

    int getAccuracy() const;
    

};