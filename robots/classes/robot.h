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



class Robot {
    protected:
    std::string name;
    std::string type;
    std::string letter;
    int xPos;
    int yPos;
    int lives;
    int kills;
    

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

    bool isTracked() const;             // for TrackBot

    virtual void executeAction() = 0;

};