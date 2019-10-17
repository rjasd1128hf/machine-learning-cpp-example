cmake_minimum_required (VERSION 3.8)
project ("machineLearning")

find_package(Ceres REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CERES_INCLUDE_DIRS = ${CERES_INCLUDE_DIRS}")
message(STATUS "CERES_LIBRARIES = ${CERES_LIBRARIES}")
include_directories(${CERES_INCLUDE_DIRS})


add_executable (simpleLinearRegression "simpleLinearRegression.cpp")
target_link_libraries(simpleLinearRegression ${CERES_LIBRARIES})
