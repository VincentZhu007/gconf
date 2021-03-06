/**
 * Copyright 2022 Vincent Zhu(VincentZhu007@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *
 * Description: 手工编写wechat json配置的解析代码，作为示例提取解析规律。
 */

#ifndef GCONF_WECHATCONF_H
#define GCONF_WECHATCONF_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "json/json.h"

namespace gconf {
namespace demo {
class WeChatConf {
public:
    WeChatConf() = default;
    int Parse(const std::string &confPath);
    int Parse(std::istream &in);
    std::vector<std::string> GetPages() const;
    std::unordered_map<std::string, std::string> GetWindow() const;

private:
    void DoParsePages(const Json::Value root);
    void DoParseWindow(const Json::Value root);
    static int DoReadJson(std::istream &in, Json::Value &root);

    std::vector<std::string> pages_ = {};
    std::unordered_map<std::string, std::string> window_ = {};
};
}
}
#endif //GCONF_WECHATCONF_H
