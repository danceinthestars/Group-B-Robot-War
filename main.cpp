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
#include <filesystem>

#include "misc/battleground.h"
#include "robots/GenericRobot.h"
#include "misc/ConfigReader.h"
#include "misc/logger.h"


int main()
{
    std::filesystem::create_directory("logs");      // create log folder

    int logNumber = 1;

    for (const auto &entry : std::filesystem::directory_iterator("logs"))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            std::string stem = entry.path().stem().string();
            try
            {
                int num = std::stoi(stem);
                if (num >= logNumber)
                    logNumber = num + 1;
            }
            catch (...) 
            {

            }  
        }
    }

    std::string logFileName = "logs/" + std::to_string(logNumber) + ".txt";
    Logger logger(logFileName);



    ConfigReader config;
    if (!config.readConfig("config.txt")) 
    {
        std::cerr << "Failed to read config.txt" << std::endl;
        return 1;
    }

    Battleground field(config.rows, config.cols, config.steps);

    for (const auto& rc : config.robots) 
    {
        if (rc.type == "GenericRobot") 
        {
            Robot* robot = new GenericRobot(rc.name, rc.type, rc.letter, rc.x, rc.y);
            field.addRobot(robot, rc.x, rc.y);
        }
    }

    std::cout << "Welcome to Robot War Simulator! Press Enter to start!" << std::endl;
    field.runGame(logger);

    logger.close();  // closes the.. logger
}