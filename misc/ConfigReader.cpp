/**********|**********|**********|
Program: ConfigReader.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "ConfigReader.h"



bool ConfigReader::readConfig(const std::string& filename)
{
    std::ifstream file(filename);
    
    if (!file.is_open()) return false;

    std::string line;

    while (std::getline(file, line)) 
    {
        if (line.find("M by N") != std::string::npos) 
        {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> cols >> rows;
        } 

        else if (line.find("steps") != std::string::npos) 
        {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> steps;
        } 
        
        else if (line.find("robots") != std::string::npos) 
        {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> robotCount;
        } 
        
        else if (!line.empty() && isalpha(line[0])) 
        {
            std::istringstream iss(line);
            RobotConfig rc;
            iss >> rc.type >> rc.name >> rc.x >> rc.y;
            robots.push_back(rc);
        }
    }

    return true;
}