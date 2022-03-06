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
#include "WeChatConf.h"
#include <fstream>

namespace gconf {
namespace demo {
int WeChatConf::Parse(const std::string &confPath)
{
    std::ifstream ifs(confPath);

    if (!ifs.is_open()) {
        std::cerr << "open json file " << confPath << " failed" << std::endl;
        return -1;
    }

    return Parse(ifs);
}

int WeChatConf::Parse(std::istream &in)
{
    Json::Value root;
    auto ret = DoReadJson(in, root);
    if (ret != 0) {
        return ret;
    }
    DoParsePages(root);
    DoParseWindow(root);
    return 0;
}

int WeChatConf::DoReadJson(std::istream &in, Json::Value &root)
{
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    std::string errs;
    bool ok = Json::parseFromStream(rbuilder, in, &root, &errs);
    if (!ok) {
        std::cerr << "parse json failed: " << errs << std::endl;
        return -2;
    }
    return 0;
}

const std::string FIELD_PAGES = "pages";

void WeChatConf::DoParsePages(const Json::Value root)
{
    auto size = root[FIELD_PAGES].size();
    for (decltype(size) i = 0; i < size; i++) {
        pages_.push_back(root[FIELD_PAGES][i].asString());
    }
}

const std::string FIELD_WINDOW = "window";

void WeChatConf::DoParseWindow(const Json::Value root)
{
    auto keys = root[FIELD_WINDOW].getMemberNames();
    for (const auto &key: keys) {
        window_.emplace(key, root[FIELD_WINDOW][key].asString());
    }
}

std::vector<std::string> WeChatConf::GetPages() const
{
    return pages_;
}

std::unordered_map<std::string, std::string> WeChatConf::GetWindow() const
{
    return window_;
}
}
}
