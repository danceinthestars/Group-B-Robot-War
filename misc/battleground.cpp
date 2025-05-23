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

// The idea is that a battleground is really just
// a table of cells, and that we have a couple of
// functions that can:
// put in robots when they spawn
// take out robots when they die
// take out a robot if they get upgraded and replace them with their new upgraded form

#include "battleground.h"

Battleground::Battleground(int rows, int cols, int maxSteps) : rows(rows), cols(cols), maxSteps(maxSteps), currentStep(1)
{
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
            output += grid[i][j]->getChar() + " ";            // display cell
        }
        output += "#\n";                                      // display right side border
    }

    output += border + "\n";                                  // display bottom border

    // then next commands display output here

    return output;
}