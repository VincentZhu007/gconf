# CMake configuration for wechat conf demo

set(TARGET wechat_conf_test)

file(GLOB TARGET_SRC
    ${CMAKE_SOURCE_DIR}/demo/wechat/WeChatConf.h
    ${CMAKE_SOURCE_DIR}/demo/wechat/WeChatConf.cpp
)

add_executable(${TARGET} wechat_conf_test.cpp ${TARGET_SRC})
target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(${TARGET} PRIVATE gtest gtest_main jsoncpp_lib)

include(GoogleTest)
gtest_discover_tests(${TARGET})
