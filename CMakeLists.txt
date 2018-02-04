
cmake_minimum_required(VERSION 3.6)

project(othello)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(Qt5_SYSTEMWIDE /home/peyman/Qt5.8.0/5.8/gcc_64)
set(Qt5_LOCAL $ENV{HOME}/Qt5.8.0/5.8/gcc_64)


message("Testing against Qt")
if(EXISTS ${Qt5_SYSTEMWIDE})
    message("System-wide Qt found!")
    set(Qt5_BASE_DIR ${Qt5_SYSTEMWIDE})
    message("Local Qt found!")
    set(Qt5_BASE_DIR ${Qt5_LOCAL})
else()
    message("No user installed Qt5 found!")
endif()

if(DEFINED Qt5_BASE_DIR)
    message("Adjust CMAKE_PREFIX_PATH")
    set(CMAKE_PREFIX_PATH ${Qt5_BASE_DIR};${CMAKE_PREFIX_PATH})
endif()

set(SOURCE_FILES main.cpp game_page.h game_page.cpp login_window.h login_window.cpp accessories.h accessories.cpp game_core.h game_core.cpp result_menu.h result_menu.cpp)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network Multimedia )
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network Qt5::Multimedia)