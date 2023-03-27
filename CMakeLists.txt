cmake_minimum_required(VERSION 3.23)
project(LAB_Programmazione)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_subdirectory(Test)
set(SOURCE_FILES sources_/main.cpp headers_/Application.h headers_/MainFrame.h headers_/Timer.h headers_/TimerType.h sources_/Application.cpp sources_/MainFrame.cpp headers_/Clock.h headers_/ClockType.h sources_/ClockType.cpp sources_/Clock.cpp sources_/Timer.cpp sources_/TimerType.cpp headers_/ChronoType.h sources_/ChronoType.cpp headers_/Chrono.h sources_/Chrono.cpp)
add_executable(LAB_Programmazione ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(LAB_Programmazione ${wxWidgets_LIBRARIES} core)