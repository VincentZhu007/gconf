cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(gconf LANGUAGES CXX)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

option(GCONF_WITH_TESTS "build gconf tests?" ON)
message(STATUS "build gconf tests? " ${GCONF_WITH_TESTS})

add_subdirectory(third_party)

add_subdirectory(demo)

add_subdirectory(src)

if(GCONF_WITH_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
