cmake_minimum_required(VERSION 3.12)
project(grafo_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(grafo_cpp src/main.cpp src/Grafo.h matriz-esparsa-cpp/src/MatrizEsparsa.h matriz-esparsa-cpp/src/Linha.h matriz-esparsa-cpp/src/WrapperColuna.h)