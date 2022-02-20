# gconf

## 简介

gconf是一个代码生成工具，它致力于：根据用户需求（DSL）生成安全、可靠的配置解析代码，将外部格式化配置（json、xml等）轻松转化为语言（C++、Java等）内置数据结构，比如类、结构体等，免去手工编写繁冗配置代码的工作量，避免复杂的配置逻辑导致的痛苦维护过程。

通常来说，配置解析本身并不是软件的关键业务。gconf可以帮助您，大幅缩短配置解析的复杂度和工作量，将宝贵的精力集中到核心业务开发中。

## 编译构建

```bash
$ cd gconf
$ mkdir build && cd build
$ cmake ..
$ make -j
$ ctest
```

## 相关文档

- gconf [开发文档](./doc/devlog.md)

- gconf [todo](./doc/todo.md)