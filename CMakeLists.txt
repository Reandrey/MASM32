cmake_minimum_required(VERSION 3.26)

set(PATH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATH_VERSION})
set(CMAKE_CXX_STANDARD 23)


project(MASM32 VERSION ${PROJECT_VERSION})


add_executable(MASM32 main.cpp)



