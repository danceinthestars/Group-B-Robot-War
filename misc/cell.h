/**********|**********|**********|
Program: cell.h
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

#include "../robots/classes/robot.h"

#include <memory>


class Cell {

    private:
    int x;
    int y;
    Robot* robot = nullptr;
    
    public:
    Cell(int x, int y);

    int getX() const;

    int getY() const;

    std::string getLetter() const;

    void placeRobot(Robot* robot);

    void removeRobot();

    bool hasRobot() const;

    Robot* getRobot() const;

};