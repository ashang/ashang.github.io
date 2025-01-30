---
layout: page
title: MPV
---

MPV 依赖 FFmpeg 进行音视频处理，FFmpeg 由多个动态库（lib）组成，各自负责不同的功能：

    libavcodec：音视频编解码库，提供各种编解码器，如 H.264、VP9、AAC 等。
    libavdevice：用于处理输入/输出设备，比如摄像头、屏幕捕获等。
    libavfilter：用于处理音视频滤镜，如调整亮度、添加字幕、去噪等。
    libavformat：用于解析音视频格式（封装/解封装），如 MP4、MKV、AVI 等。
    libavutil：提供通用工具，如数学计算、时间戳处理、颜色转换等。
    libswresample：用于音频重采样，比如调整采样率、格式转换等。
    libswscale：用于视频缩放、像素格式转换等，比如 RGB ↔ YUV。
