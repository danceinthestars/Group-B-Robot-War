/**********|**********|**********|
Program: battleground.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

// The idea is that a battleground is really just
// a table of cells, and that we have a couple of
// functions that can:
// put in robots when they spawn
// take out robots when they die
// take out a robot if they get upgraded and replace them with their new upgraded form

#include "battleground.h"



Battleground::Battleground(int rows, int cols, int maxSteps) 
             : rows(rows), cols(cols), maxSteps(maxSteps)
{
    grid.resize(rows); 
    for (int i = 0; i < rows; ++i) 
    {
        grid[i].resize(cols);
        for (int j = 0; j < cols; ++j) 
        {
            grid[i][j] = std::make_unique<Cell>(i, j);
        }
    }
}

std::string Battleground::displayBattleground()
{
    std::string border;
    std::string output;

    for (int i = 0; i < rows * 2 + 3; i++)
    {
        border += (i % 2 == 0) ? "#" : " ";                   // when i % 2 == 0, display "#"; if not, display " ". necessary spacing to make the grid look correct
    }
    output += border + "\n";                                  // display top border

    for (int j = cols - 1; j >= 0; j--)
    {
        output += "# ";                                       // display left side border
        for (int i = 0; i < rows; i++)
        {
            output += grid[i][j]->getLetter() + " ";          // display cell
        }
        output += "#\n";                                      // display right side border
    }

    output += border + "\n";                                  // display bottom border

    // then next commands display output here

    return output;
}

int Battleground::getRows() const
{
    return rows;
}

int Battleground::getCols() const
{
    return cols;
}

int Battleground::getMaxSteps() const
{
    return maxSteps;
}

int Battleground::getCurrentStep()
{
    return currentStep;
}

Cell* Battleground::getCell(int x, int y) const
{
    if (x < 0 || x >= rows || y < 0 || y >= cols) return nullptr;  // check if the coordinates are within bounds
    return grid[x][y].get();
}

void Battleground::addRobot(Robot* robot, int x, int y)
{
    Cell* cell = getCell(x, y);
    if (cell && !cell->hasRobot()) 
    {
        cell->placeRobot(robot);
        robots.push_back(robot);
    }

    // set else here if necessary to handle a case where the cell is occupied

}


void Battleground::runGame()
{
    std::cin.ignore();

    for (currentStep = 1; currentStep <= maxSteps; ++currentStep)     // add "if there still has more than 1 robot" requirement later
    {
        for (Robot* robot : robots)
        {
            if (robot)
                robot->executeAction(*this, actionLog);
        }

        std::cout << displayBattleground();
        
        std::cout << "\nTurn " << getCurrentStep() << "/" << getMaxSteps() << ":" << std::endl;

        for (const auto& msg : actionLog) 
        {
            std::cout << msg << std::endl;
        }

        actionLog.clear();  

        std::cout << "Press Enter to proceed to the next step..." << std::endl;
        std::cin.get();
    }

    std::cout << "Game Over!" << std::endl;

}