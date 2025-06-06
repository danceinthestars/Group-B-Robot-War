/**********|**********|**********|
Program: randomizer.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "randomizer.h"
#include <random>

int Randomizer::generateRandom(int a, int b)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}