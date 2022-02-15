# gconf developing log

1、起源

考虑在C++项目中，手工编写代码提取json配置
- 一方面，安全、可靠、高效的解析代码，内部实现可能十分繁冗。
- 另一方面，解析代码本身具有一定的规律性，可以提取通用的编码特征。

2、提取conf特征--配置解析模型

wechat配置demo

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

- [ ] task1：手工编写代码解析wechat配置



