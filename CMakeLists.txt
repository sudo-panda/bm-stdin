cmake_minimum_required(VERSION 3.0.2)
project (InputBenchmark)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" )
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package(Git REQUIRED)
include(ExternalProject)

ExternalProject_Add(
        Celero
        GIT_REPOSITORY https://github.com/DigitalInBlue/Celero.git
        UPDATE_COMMAND ""
        INSTALL_DIR ${CMAKE_BINARY_DIR}/Celero
        CMAKE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX:STRING=${CMAKE_BINARY_DIR}/Celero
        -DCELERO_COMPILE_DYNAMIC_LIBRARIES:BOOL=OFF
        -DCELERO_ENABLE_EXPERIMENTS:BOOL=OFF
        -DCELERO_ENABLE_FOLDERS:BOOL=OFF)
ExternalProject_Get_Property(Celero SOURCE_DIR)
ExternalProject_Get_Property(Celero INSTALL_DIR)
set(CELERO_INSTALL_DIR ${INSTALL_DIR})

include_directories(${CELERO_INSTALL_DIR}/include)
add_library(libcelero STATIC IMPORTED)
set_property(TARGET libcelero PROPERTY
        IMPORTED_LOCATION_DEBUG
        "${CELERO_INSTALL_DIR}/lib/static/${CMAKE_STATIC_LIBRARY_PREFIX}celerod${CMAKE_STATIC_LIBRARY_SUFFIX}")
set_property(TARGET libcelero PROPERTY
        IMPORTED_LOCATION_RELEASE
        "${CELERO_INSTALL_DIR}/lib/static/${CMAKE_STATIC_LIBRARY_PREFIX}celero${CMAKE_STATIC_LIBRARY_SUFFIX}")
add_dependencies(libcelero Celero)


add_executable(stdin_bm src/stdin_bm.cpp)
add_dependencies(stdin_bm libcelero)
target_link_libraries(stdin_bm libcelero ${CELERO_EXTRA_LIBS})