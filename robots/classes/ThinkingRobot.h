/**********|**********|**********|
Program: ThinkingRobot.h
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/




// from what I can tell, ThinkingRobot is supposed to run all of the
// thinking algorithms of a robot
// figure it out later; ill set the stuff to random for now LUL

// implement a target() to optimise which robot to go for after a look()
// maybe genericrobot will have a consult() that refers to here, and it will return
// what function to use depending on robot type?


#pragma once

#include "robot.h"
#include "../../misc/battleground.h"

#include <vector>
#include <string>



class ThinkingRobot : virtual public Robot
{
    using Robot::Robot;

    public:
    Robot* findEnemy(const Battleground& field);
};