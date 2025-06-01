/**********|**********|**********|
Program: SeeingRobot.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "SeeingRobot.h"
#include "../../misc/cell.h"

std::vector<std::vector<std::string>> SeeingRobot::look(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog) const
{
    std::vector<std::vector<std::string>> area(3, std::vector<std::string>(3));

    int centerX = getXPos() + dx;       // the centre coords of the m x n area where the robot is looking
    int centerY = getYPos() + dy;

    actionLog.push_back(getName() + " (" + getLetter() + ") looked around (" + std::to_string(centerX) + ", " + std::to_string(centerY) + ").");

    for (int i = -1; i <= 1; ++i)       // i and j go from -1 to 1, it should still work; i think the calculations just look nicer this way
    {
        for (int j = -1; j <= 1; ++j) 
        {

            int x = centerX + i;
            int y = centerY + j;

            if (x < 0 || x >= field.getRows() || y < 0 || y >= field.getCols()) 
            {
                area[i + 1][j + 1] = "OUT";                 // sees out of bounds
            } 
            
            else 
            {
                Cell* cell = field.getCell(x, y);

                if (cell->hasRobot()) 
                {
                    Robot* other = cell->getRobot();

                    if (other == this) 
                    {
                        area[i + 1][j + 1] = "SELF";        // sees itself
                    } 
                    else 
                    {
                        area[i + 1][j + 1] = "ENEMY";       // sees an enemy
                    }
                } 
                else 
                {
                    area[i + 1][j + 1] = "EMPTY";           // sees an empty spot it can move to
                }
            }
        }
    }

    return area;

}

std::vector<std::vector<std::string>> SeeingRobot::scout(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog)
{
    if (seeUpgradeID != 1 || scoutCount <= 0) 
    {
        return {};
    }

    else
    {
        actionLog.push_back(getName() + " (" + getLetter() + ") scouted the whole map!");

        int rows = field.getRows();
        int cols = field.getCols();
        std::vector<std::vector<std::string>> area(rows, std::vector<std::string>(cols));

        for (int x = 0; x < rows; ++x) 
        {
            for (int y = 0; y < cols; ++y) 
            {
                Cell* cell = field.getCell(x, y);
                if (cell->hasRobot()) 
                {
                    Robot* other = cell->getRobot();
                    if (other == this) 
                    {
                        area[x][y] = "SELF";
                    } 
                    
                    else 
                    {
                        area[x][y] = "ENEMY";
                    }

                }
                else 
                {
                    area[x][y] = "EMPTY";
                }
            }
        }

        scoutCount--;


        return area;
    }


}

std::vector<std::vector<std::string>> SeeingRobot::receiveTrackedPositions(int dx, int dy, const Battleground& field, std::vector<std::string>& actionLog) const
{
    int rows = field.getRows();     // gets the whole map and sees all the enemies
    int cols = field.getCols();
    std::vector<std::vector<std::string>> area(rows, std::vector<std::string>(cols, "EMPTY"));

    for (Robot* tracked : getTrackedRobots()) {

        int x = tracked->getXPos();
        int y = tracked->getYPos();

        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            area[x][y] = "ENEMY";
        }
    }
    
                // NOTE: if robot does look(), it would override the tracked area so the 
                // robot would not be able to see the robots its tracked anymore
}