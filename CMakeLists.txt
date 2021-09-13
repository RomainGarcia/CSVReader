cmake_minimum_required(VERSION 3.20)
project(CSVReader)

set(CMAKE_CXX_STANDARD 20)

add_executable(CSVReader main.cpp Csv.cpp Csv.h)
