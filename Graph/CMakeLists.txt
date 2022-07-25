cmake_minimum_required(VERSION 3.20)
project(MST)

set(CMAKE_CXX_STANDARD 14)

add_executable(MST Dijkstra.cpp MGraph.cpp main.cpp Kruscal.cpp UnionFind.cpp Floyd.cpp DAG.cpp)
