# wechat conf lib
file(GLOB wechatconf_src
    WeChatConf.h
    WeChatConf.cpp
)
add_library(wechatconf ${wechatconf_src})
target_link_libraries(wechatconf PUBLIC jsoncpp_lib)