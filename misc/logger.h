/**********|**********|**********|
Program: logger.h
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

#include <fstream>
#include <string>
#include <vector>
#include <filesystem>



class Logger 
{
    private:
    std::ofstream ofs;

    public:
    Logger(const std::string& filename);
    
    void log(const std::string& message);
    void log(const std::vector<std::string>& messages);
    
    void close();
};