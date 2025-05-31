cmake_minimum_required(VERSION 3.10)
project(RobotWar)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    main.cpp
    misc/battleground.cpp
    misc/cell.cpp
    misc/ConfigReader.cpp
    misc/logger.cpp
    misc/randomizer.cpp
    robots/GenericRobot.cpp
    robots/classes/robot.cpp
    robots/classes/MovingRobot.cpp
    robots/classes/SeeingRobot.cpp
    robots/classes/ShootingRobot.cpp
    robots/classes/ThinkingRobot.cpp
)

# Add the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(robotwar ${SOURCES})