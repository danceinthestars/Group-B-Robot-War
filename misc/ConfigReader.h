/**********|**********|**********|
Program: ConfigReader.cpp
Course: OOPDS
Trimester: 2510
Name: Nur Damia Adlina Binti Kamarulazizi 
ID: 242UC244TE
Lecture Section: TC3L
Tutorial Section: TT9L
Email: nur.damia.adlina@student.mmu.edu.my
Phone: 019-7843211
**********|**********|**********/

#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>


struct RobotConfig
{
    std::string type;
    std::string name;
    std::string letter;
    std::string xStr;
    std::string yStr;
    int x;
    int y;
};

class ConfigReader
{
    public:
    
    int rows = 0;
    int cols = 0;
    int steps = 0;
    int robotCount = 0;
    std::vector<RobotConfig> robots;

    bool readConfig(const std::string& filename);

    void giveLetter();

    // this is for to make sure that two or more robots dont spawn in the same place
    std::pair<int, int> setCoordinate(
        const std::string& xStr,
        const std::string& yStr,
        std::set<std::pair<int, int>>& usedCoords,
        int rows,
        int cols);

};

