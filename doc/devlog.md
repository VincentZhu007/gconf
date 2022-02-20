# gconf developing log

## 起源

在一个C++项目，需要手工编写外部jsoncpp配置的解析代码，来提取业务配置信息。

这种手工配置解析编码存在一些问题：

- 为了达到安全、可靠的效果，解析代码的实现十分繁冗。
- 随着迭代演进导致配置逻辑变复杂，修改这些代码极其痛苦。

## gconf定位

Q：gconf解决什么问题？带来什么价值？

A：一个可以帮用户生成配置解析代码的工具。用户可以在gconf提供的代码基础上做定制开发，快速实现可靠安全的复杂配置解析功能。

Q：gconf的用户是谁？

A：软件开发者，他们需要手写繁冗的配置解析代码。

Q：用户痛点是什么？

A：编写配置解析代码，将特定配置格式转换为开发语言（如C++）容易操作的类型，很容易会发现以下几个问题：

- 为了校验外部配置的合法性，通常需要编写<u>重复</u>、<u>枯燥</u>的校验代码；
- 随着配置规模增加以及校验逻辑变得复杂，编写和维护正确可靠的代码需要花费大量的精力，但配置往往并不是项目的核心竞争力。

Q：gconf需要提供什么功能？

A：针对用户的两个重要痛点：

- 痛点1：合法性校验；

- 痛点2：配置变更。

可以看出，gconf需要提供功能，以满足：

- 方便易用的合法性校验功能，最好是预置校验逻辑，用户直接选配即可；
- 能够直观、方便地修改配置解析逻辑。

## 从手工编码开始

### 手工实现wechat配置demo

```json
{
  "pages": [
    "pages/index/index",
    "pages/logs/index"
  ],
  "window": {
    "navigationBarTitleText": "Demo"
  },
  "tabBar": {
    "list": [{
      "pagePath": "pages/index/index",
      "text": "首页"
    }, {
      "pagePath": "pages/logs/index",
      "text": "日志"
    }]
  },
  "networkTimeout": {
    "request": 10000,
    "downloadFile": 10000
  },
  "debug": true
}
```

json来源：https://developers.weixin.qq.com/miniprogram/dev/framework/config.html#%E5%85%A8%E5%B1%80%E9%85%8D%E7%BD%AE


