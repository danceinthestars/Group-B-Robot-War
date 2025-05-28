/**********|**********|**********|
Program: main.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include <iostream>
#include <memory>

#include "misc/battleground.h"
#include "robots/GenericRobot.h"
#include "misc/ConfigReader.h"



int main()
{
    ConfigReader config;
    if (!config.readConfig("config.txt")) {
        std::cerr << "Failed to read config.txt" << std::endl;
        return 1;
    }

    Battleground field(config.rows, config.cols, config.steps);

    for (const auto& rc : config.robots) {
        if (rc.type == "GenericRobot") {
            Robot* robot = new GenericRobot(rc.name, rc.type, rc.name.substr(0,1), rc.x, rc.y);
            field.addRobot(robot, rc.x, rc.y);
        }
        // Add more robot types here if needed
    }

    std::cout << "Welcome to Robot War Simulator! Press Enter to start!" << std::endl;
    field.runGame();
}