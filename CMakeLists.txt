﻿cmake_minimum_required( VERSION 3.8 )

project( HFLib )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

#set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

add_subdirectory( HFLib )
add_subdirectory( tests )
