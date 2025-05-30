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
#include "randomizer.h"



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

int Battleground::getCurrentStep() const
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

        respawnRobot();

        for (Robot* robot : robots)
        {
            if (robot->isAlive())
            {
                robot->executeAction(*this, actionLog);
            };
            
        }

        std::cout << displayBattleground();

        std::cout << "Respawn Queue: ";
        for (Robot* robot : respawnQueue) 
        {
            std::cout << robot->getName() << "(" << robot->getLetter() << ") ";
        }
        std::cout << std::endl;
        
        
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

void Battleground::selfDestruct(Robot* robot)
{
    robot->setAlive(false);

    Cell* cell = getCell(robot->getXPos(), robot->getYPos());
    cell->removeRobot(); // robot DIE

    int lives = robot->getLives();
    robot->setLives(lives - 1);

    if (robot->getLives() > 0)       // if still have lives
    {
        respawnQueue.push_back(robot);

        actionLog.push_back(robot->getName() + " (" + robot->getLetter() + ") died! Remaining lives: " + std::to_string(robot->getLives()));
        
    } 
    
    else        // no more lives to respawn with
    {
        actionLog.push_back(robot->getName() + " (" + robot->getLetter() + ") died and is out of lives! It is out of the game!");
    }
}

void Battleground::killRobot(Robot* killer, Robot* target)
{
    selfDestruct(target);   // i realise i could just run this instead of copying the code oops

    int newKills = killer->getKills();
    killer->setKills(newKills + 1);

    // killer->upgrade(); REMEMBER TO IMPLEMENT THIS!!!!!!!!
}

void Battleground::respawnRobot()
{
    if (respawnQueue.empty()) return;

    Robot* respawnedRobot = respawnQueue.front(); // grabs the robot in the front of the queue
    respawnQueue.erase(respawnQueue.begin()); // removes said robot from the queue

    int x;
    int y;

    do {
        x = Randomizer::generateRandom(0, getRows() - 1);
        y = Randomizer::generateRandom(0, getCols() - 1);
    } while (grid[x][y]->hasRobot());


    respawnedRobot->setXPos(x);
    respawnedRobot->setYPos(y);
    respawnedRobot->setAlive(true);
    
    grid[x][y]->placeRobot(respawnedRobot);

    respawnedRobot->setShells(10); // REMEMBER TO ADD TO THIS ONCE YOU IMPLEMENT 30SHELLBOT

    actionLog.push_back(respawnedRobot->getName() + " (" + respawnedRobot->getLetter() + ") has respawned at (" + std::to_string(x) + ", " + std::to_string(y) + ")!");
    
}