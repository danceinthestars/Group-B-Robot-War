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
    int kills;
    int shells;
    bool alive;
    

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

    int getKills() const;

    int getShells() const;

    bool isAlive() const;

    bool isTracked() const;             // for TrackBot

    virtual void executeAction(Battleground& field, std::vector<std::string>& actionLog) = 0;

    void setLives(int newLives);

    void setKills(int newKills);

    void setAlive(bool status);

};