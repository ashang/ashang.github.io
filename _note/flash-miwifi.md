---
title: flashing mi wifi r1
tags: ["flashing", "ROM"]
date: 2015-08-12
---

1、首先在路由器后台查看R1的IP地址，用ADB无线连接R1选择上传es文件浏览器APK安装包并安装，然后用投屏工具连到R1打开es文件浏览器。

2、修改 r1 屏分辨率，原r1的分辨率是720x480 建议修改为 720x576 >为QQ音乐授权 准备adb shell wm size 720x576修改R1的系统语言为中文。

## 安装Webview组件

Webview文件夹 复制到 system/app/目录下

libwebviewchromium.so libwebviewchromium_loader.so libwebviewchromium_plat_support.so 三个so文件复制到system/lib/目录下

xiaoai.sh是小爱同学的开机脚本 复制到data/adb/sevice.d/目录下

MyAndroidToolsPro1.6.0.apk 这个app用来禁用 小爱同学，qq音乐不需要的服务，禁用用不着的app

三、完成

- 小爱调用 喜码拉牙 讲故事

- 登录小爱同学 控制 米家设备

- 设置闹钟&#9200;，

- 保留系统，蓝牙、dlna、airplayer，全局氛围灯

- ps（修改系统为中文语言，设置系统分辨率为780x580）

- 小爱同学 直接使用 qq音乐播放歌曲

