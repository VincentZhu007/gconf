add_executable(wechat_parser wechat_parser.cpp)
target_link_libraries(wechat_parser jsoncpp_lib)

# wechat conf lib
file(GLOB src
        WeCharConf.h
        WeCharConf.cpp
)
add_library(wechatconf ${src})
target_link_libraries(wechatconf jsoncpp_lib)