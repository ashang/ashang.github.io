---
layout: post
title: "Uploading Podcast Audio to YouTube"
meta: "Simple way of uploading audio tracks to YouTube."
---

YouTube unfortunately does not provide you with the ability to upload audio tracks individually, which is a pain if you do not work with video (such as a podcast).
The way to get around this limitation is to create a video which includes the desired audio track and a fixed image (i.e. cover-art) which lasts the duration of the track.
There are many ways of achieving such a result, from iMovie and Windows Movie Maker to the online service [TunesToTube](http://www.tunestotube.com/).
With a little [research](https://trac.ffmpeg.org/wiki/EncodeforYouTube) however, I was able to come up with a even simpler solution that only requires the ever useful [ffmpeg](http://www.ffmpeg.org).
<!--more-->

{% highlight bash %}
$ ffmpeg -loop 1 -r 2 -i image.jpg -i input.mp3 -vf scale=-1:380 -c:v libx264 -preset slow \
    -tune stillimage -crf 18 -c:a copy -shortest -pix_fmt yuv420p -threads 0 output.mkv
{% endhighlight %}

{% highlight bash %}
-loop 1           # loop over image stream
-r 2              # frame rate
-i image.jpg      # image input file
-i input.mp3      # audio input file
-vf scale=-1:380  # apply scale filter, resize to 380p
-c:v libx264      # encode video to H.264 using libx264 library
-preset slow      # sets encoding preset for x264
-tune stillimage  # x264 input preset
-crf 18           # constant rate factor
-c:a copy         # copy over audio input
-shortest         # finish when shortest input ends
-pix_fmt yuv420p  # set pixel format
-threads 0        # optimal number of threads to encode
output.mkv        # output file
{% endhighlight %}