cmake_minimum_required(VERSION 3.17)
project(Design_Pattern_Composite)

set(CMAKE_CXX_STANDARD 20)

add_executable(Design_Pattern_Composite main.cpp Component.cpp Component.h Composite.cpp Composite.h Leaf.cpp Leaf.h Color.cpp Color.h)