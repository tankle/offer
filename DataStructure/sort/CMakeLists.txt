cmake_minimum_required(VERSION 3.2)
project(sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BOOST_ROOT "D:\\local\\boost_1_58_0")
set(BOOSTROOT "D:\\local\\boost_1_58_0")

find_package(Boost 1.58.0)

IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

set(SOURCE_FILES
    main.cpp)

add_executable(sort ${SOURCE_FILES})