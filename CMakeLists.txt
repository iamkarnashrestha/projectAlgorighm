cmake_minimum_required(VERSION 3.26)
project(PoojaAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(PoojaAlgorithm main.cpp
        Graph.cpp
        Graph.h
        MinHeap.cpp
        MinHeap.h
        Dijkstra.cpp
        Dijkstra.h
        Prim.cpp
        Prim.h
)
