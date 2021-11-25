cmake_minimum_required(VERSION 3.15)
project(R_P_S_Game)


aux_source_directory(. SRC_LIST)
set(CMAKE_CXX_STANDARD 14)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(snakeGame Backend.h Backend.cpp Snake.h Snake.cpp game.h game.cpp timer.h timer.cpp constants.h)
target_link_libraries(snakeGame ${wxWidgets_LIBRARIES})

#set(CMAKE_CXX_STANDARD 14)
