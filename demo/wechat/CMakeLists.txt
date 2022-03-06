add_executable(wechat_parser wechat_parser.cpp)
target_link_libraries(wechat_parser jsoncpp_lib)

# wechat conf lib
file(GLOB wechatconf_src
        WeChatConf.h
        WeChatConf.cpp
)
add_library(wechatconf ${wechatconf_src})
target_link_libraries(wechatconf INTERFACE jsoncpp_lib)