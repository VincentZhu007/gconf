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
 * Description: wechat解析函数测试
 */
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class WeChatConfTest: public ::testing::Test
{
protected:
    static void SetUpTestCase()
    {
        cout << "setup test suit" << endl;
    }
    static void TearDownTestCase()
    {
        cout << "tear down test suit" << endl;
    }
    void SetUp()
    {
        cout << "setup" << endl;
    }
    void TearDown()
    {
        cout << "tear down" << endl;
    }
};



