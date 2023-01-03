cmake_minimum_required(VERSION 3.10)

project(Racing)

add_library(RaceLib SHARED 
RaceLib/RaceLib.h 
RaceLib/Boots.h 
RaceLib/Boots.cpp 
RaceLib/Broom.h 
RaceLib/Broom.cpp 
RaceLib/Camel.h 
RaceLib/Camel.cpp 
RaceLib/CamelFast.h 
RaceLib/CamelFast.cpp 
RaceLib/Carpet.h 
RaceLib/Carpet.cpp 
RaceLib/Centaur.h 
RaceLib/Centaur.cpp 
RaceLib/Eagle.h 
RaceLib/Eagle.cpp 
RaceLib/Vehicle.h 
RaceLib/Vehicle.cpp 
RaceLib/VehicleAir.h 
RaceLib/VehicleAir.cpp 
RaceLib/VehicleLand.h 
RaceLib/VehicleLand.cpp)

add_executable(RacingSimulator 
RacingSimulator/RacingSimulator.cpp 
RacingSimulator/myFunc.h 
RacingSimulator/myFunc.cpp)

target_link_libraries(RacingSimulator RaceLib)
