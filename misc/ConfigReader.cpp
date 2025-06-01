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

#include "ConfigReader.h"
#include "randomizer.h"
#include <set>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


bool ConfigReader::readConfig(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) return false;

    std::string line;
    std::set<std::pair<int, int>> usedCoords;

    while (std::getline(file, line)) 
    {
        if (line.find("M by N") != std::string::npos) 
        {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> rows >> cols;
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
        
        else if (!line.empty() && ((line[0] >= 'A' && line[0] <= 'Z') || (line[0] >= 'a' && line[0] <= 'z'))) 
        {
            std::istringstream iss(line);
            RobotConfig rc;
            iss >> rc.type >> rc.name >> rc.xStr >> rc.yStr;

            auto [x, y] = setCoordinate(rc.xStr, rc.yStr, usedCoords, rows, cols);
            rc.x = x;
            rc.y = y;

            robots.push_back(rc);
        }
    }

    giveLetter();

    return true;
}

void ConfigReader::giveLetter()
{
    char current = 'A';
    for (auto& rc : robots) {
        rc.letter = std::string(1, current); 
        current++;
        if (current > 'Z') current = 'A'; 
    }
}

std::pair<int, int> ConfigReader::setCoordinate(
    const std::string& xStr,
    const std::string& yStr,
    std::set<std::pair<int, int>>& usedCoords,
    int rows,
    int cols)
{
    bool xRandom = (xStr == "random");      // check if x or y is set as random
    bool yRandom = (yStr == "random");
    int x, y;

    do {
        if (xRandom) 
        {
            x = Randomizer::generateRandom(0, rows - 1);    // if set as random, randomise
        } 
        
        else 
        {
        bool isXNumeric = true;
        for (char ch : xStr) {
            if (ch < '0' || ch > '9') {
                isXNumeric = false;
                break;
            }
        }
        if (!isXNumeric)
        throw std::runtime_error("Invalid x coordinate: " + xStr);  // if anything else, error!!!
        
        x = std::stoi(xStr);

        }

        if (yRandom) 
        {
            y = Randomizer::generateRandom(0, cols - 1);
        } 
        
        else 
        {
        bool isYNumeric = true;
        for (char ch : yStr) {
            if (ch < '0' || ch > '9') {
                isYNumeric = false;
                break;
            }
        }
        
        if (!isYNumeric)
        throw std::runtime_error("Invalid y coordinate: " + yStr);
        
        y = std::stoi(yStr);
        }

        if (x < 0 || x >= rows || y < 0 || y >= cols)   // checks if coords are out of the map
            throw std::runtime_error("Coordinates out of bounds: (" + std::to_string(x) + ", " + std::to_string(y) + ")");

        if (!xRandom && !yRandom && usedCoords.count({x, y}) > 0)
            throw std::runtime_error("Duplicate robot coordinates at (" + std::to_string(x) + ", " + std::to_string(y) + ")");

        if ((xRandom || yRandom) && usedCoords.count({x, y}) > 0)
            continue;

        break;
    } while (true);

    usedCoords.insert({x, y});
    return {x, y};
}