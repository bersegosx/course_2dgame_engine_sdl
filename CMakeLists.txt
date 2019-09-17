cmake_minimum_required(VERSION 3.7)

project(2dgame_engine)

file(GLOB SOURCE_FILES src/*.*)

INCLUDE(FindPkgConfig)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

#find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS}/include ${SDL2_INCLUDE_DIRS}/include/SDL2)

