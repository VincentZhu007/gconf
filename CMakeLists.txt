cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(gconf LANGUAGES CXX)

set(CXX_STANDARD 11)

include(FetchContent)

# third_party module: jsoncpp
FetchContent_Declare(jsoncpp
        URL https://github.com/open-source-parsers/jsoncpp/archive/1.9.4.tar.gz)
FetchContent_MakeAvailable(jsoncpp)

add_subdirectory(src)

add_subdirectory(test)

add_subdirectory(demo)
