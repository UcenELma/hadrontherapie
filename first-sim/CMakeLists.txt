cmake_minimum_required(VERSION 3.10 FATAL_ERROR)  # Specify minimum version

project(Simulation)  # Project name

find_package(Geant4 REQUIRED COMPONENTS ui_all vis_all)  # Find Geant4 with UI and visualization

include(${Geant4_USE_FILE})  # Use Geant4 libraries

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)  # Find source files
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)  # Find header files

add_executable(sim sim.cc ${sources} ${headers})  # Create executable

target_link_libraries(sim ${Geant4_LIBRARIES})  # Link with Geant4 libraries

add_custom_target(Simulation DEPENDS sim)  # Define custom target
