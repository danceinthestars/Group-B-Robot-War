/**********|**********|**********|
Program: logger.cpp
Course: OOPDS
Trimester: 2510
Name: Lee Ming Fung
ID: 243UC247K7
Lecture Section: TC3L
Tutorial Section: TT9L
Email: LEE.MING.FUNG@student.mmu.edu.my
Phone: 018-2021399
**********|**********|**********/

#include "logger.h"

Logger::Logger(const std::string& filename) : ofs(filename, std::ios::out)
{

}

void Logger::log(const std::string& message) 
{
    ofs << message << std::endl;
}

void Logger::log(const std::vector<std::string>& messages) 
{
    for (const auto& msg : messages) {
        ofs << msg << std::endl;
    }
}

void Logger::close() {
    ofs.close();
}