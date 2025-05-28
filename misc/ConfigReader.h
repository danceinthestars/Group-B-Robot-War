/**********|**********|**********|
Program: ConfigReader.h
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct RobotConfig
{
    std::string type;
    std::string name;
    int x;
    int y;
};

class ConfigReader
{
    private:


    public:
    int rows = 0;
    int cols = 0;
    int steps = 0;
    int robotCount = 0;
    std::vector<RobotConfig> robots;

    bool readConfig(const std::string& filename);
};