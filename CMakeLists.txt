cmake_minimum_required(VERSION 2.8)

project(ComplexVector)

#aux_source_directory(. SRC_LIST)

set(VECTOR_SRC main.cpp complexnumber.cpp complexvector.cpp complexvector1.cpp complexvector0.cpp)
set(VECTOR_HDR complexnumber.h complexvector.hpp complexvector1.hpp complexvector0.hpp Factory.hpp FactoryHori.hpp FactoryVert.hpp)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
