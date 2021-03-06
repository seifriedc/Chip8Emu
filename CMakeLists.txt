cmake_minimum_required(VERSION 3.10)
project(chip8emu)
set(CMAKE_CXX_STANDARD 11)

###############################################################################
## sources ####################################################################
###############################################################################

file(GLOB sources               src/*.cpp)
file(GLOB sources_testscreen1   src/tests/screen/screen_testing.cpp src/Screen.cpp)
file(GLOB sources_testscreen2   src/tests/screen/test.cpp src/Screen.cpp)

file(GLOB includes              include/*.h)
file(GLOB includes_test_screen  include/Screen.h)

###############################################################################
## targets ####################################################################
###############################################################################

add_executable(chip8emu     ${sources})
add_executable(chip8dis     src/chip8dis/CHIP8Dis.c)
add_executable(testscreen1  ${sources_testscreen1})
add_executable(testscreen2  ${sources_testscreen2})

target_include_directories(chip8emu PUBLIC include/)
target_include_directories(testscreen1 PUBLIC include/)
target_include_directories(testscreen2 PUBLIC include/)

target_compile_options(chip8emu PUBLIC -Wall)

###############################################################################
## dependencies ###############################################################
###############################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIR})
    target_link_libraries(chip8emu ${SDL2_LIBRARY})
    target_link_libraries(testscreen1 ${SDL2_LIBRARY})
    target_link_libraries(testscreen2 ${SDL2_LIBRARY})
endif()