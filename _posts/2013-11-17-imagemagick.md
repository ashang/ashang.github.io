---
title: ImageMagick
date: 2015-03-18
tags: ["Apps"]
---

[ImageMagick](http://www.imagemagick.org)
是一套用来创建、编辑和创作位图的软件包。它可以读取、转换及写入许多种格式的图像。同时，它也可以对图像进行裁剪、更改颜色、应用不同的效果等处理。另外，还可以旋转、合成图像，将文字、线条、多边形、椭圆形、贝塞尔曲线等添加到图像中。

ImageMagick 的多数功能可以从命令行得到使用。但更多的是，从使用
C、Ch、C++、Java、Lisp、Pascal、Perl、PHP、Python、Ruby、Tcl/Tk
等程序语言编写的程序中使用其特性。这使自动和动态修改或创建图像成为可能。

ImageMagick 支持大约 100 种图像文件格式，包括
GIF、JPEG、JPEG-2000、PNG、PDF、PhotoCD、TIFF、DPX 等。

    convert -crop 1150x200+30+120 input.png output.png

# 制作索引图和动画
!/bin/bash
montage -bordercolor red -borderwidth 3 -label "%f" -tile 5x3 *.JPG montage.jp
g
mogrify -format gif *.JPG
display montage.jpg
animate *.JPG

缩放 convert -sample 80x40 input.jpg output.jpg #注意：缩放后图像保持原来的长宽
比例 convert -sample 25%x25% input.jpg output.jpg
为当前目录的所有图像生成缩略图
for img in `ls *.jpg`
do
convert -sample 25%x25% $img thumb-$img
done

获取文件信息 libtiff
tiffinfo filename.tiff
pnginfo filename.png

可以使用 ImageMagick 的 identify
identify -verbose sample.png
identify -format "%wx%h" sample.png

旋转图像
convert -rotate 90 input.jpg output.jpg

更改文件类型
convert input.jpg output.png

为图像增加注释文字
convert -font helvetica -fill white -pointsize 36 \
-draw 'text 10,50 "Floriade 2002, Canberra, Australia"' \
floriade.jpg comment.jpg
convert -font fonts/1900805.ttf -fill white -pointsize 36 \
-draw 'text 10,475 "stillhq.com"' \
floriade.jpg stillhq.jpg

特殊效果
convert -charcoal 2 input.jpg output.jpg #炭笔
convert -colorize 255 input.jpg output.jpg #着色 可以指定三种颜色 red/green/bl
ue
convert -implode 4 input.jpg output.jpg #内爆效果
convert -solarize 42 input.jpg output.jpg #曝光，模拟胶片曝光
convert -spread 5 input.jpg output.jpg #随机移动，参数是位移大小

一次执行多个操作
convert -sample 25%x25% -spread 4 -charcoal 4 input.jpg output.jpg

topImageMagick FAQ 摘要
如何让animate在显示图片的过程保持窗口的标题不变
animate -title "My Image Sequence" images.

import抓得的图片与X服务器上显示的不一致怎么办？
import -descend image.miff

如何动画显示YUV 图片序列?
animate -geometry 352x240 -scene 0-71 yuv3:frame%d

如果只看一个RGB图片的红色通道(red channel)?
display -gamma 1.0,0.0,0.0 image.miff

如何改变PostScript默认纸张大小?
要改变默认的612x792大小，修改magick/image.h中的PSPageGeometry的值并重编译.
如何自左至右无边无框无文字半三幅画连接在一起？
convert +append image1.ppm image2.ppm image3.ppm side_by_side.miff
# 或
convert -size 350x500 xc:black composite.miff
composite -geometry +0+0 composite.miff image1.gif composite.miff
composite -geometry +100+0 composite.miff image2.gif composite.miff
composite -geometry +0+300 composite.miff image3.gif composite.miff
composite -geometry +0+375 composite.miff image4.gif composite.miff

如何生成gif动画?
convert -delay 20 frame*.gif animation.gif
convert -delay 20 frame1.gif -delay 10 frame2.gif -delay 5 frame3.gif animatio
n.gif
convert frame1.gif -page +50+100 frame2.gif -page +0+100 frame3.gif animation.
gif
convert -loop 50 frame*.gif animation.gif
convert +adjoin images.* frames%d.gif

如果完整的显示PostScript图片？
display -page letter image.ps

什么是图片目录？如何使用它们?
#图片目录（visual image directory ，VID）的创建：
montage *.jpg directory.vid
convert 'vid:*.jpg' directory.vid
#显示图片目录
display directory.vid
display vid:movie.mpg

如果带框架保存一个窗口?
xwininfo -frame
import -frame -window ID window.miff

图片以单一颜色（a solid color）显示，是怎么回事？ 图片被破坏，或含有值为0的mat
te层，试着:
display +matte image.miff

出现 "???? library is not available ..."是怎么回事? 没安装相关的函数库。参见安
装说明。
如何查看图片不光滑层(matte channel)的值？
convert image.tiff image.matte
display -size 640x480 gray:image.matte

运行"Convert in.gif out.png" 时显示 "Invalid Parameter - out. 你运行的convert是
windows的分区类型转换程序。
如何在图片增加斜角?
#对图片边缘的处理共分四类。
1）增加有色边
convert -bordercolor red -border 25x25 image.jpg image.gif
2）加亮或变暗图片边缘，以增强3D效果
convert -raise 25 image.jpg image.gif
3）在图片周围增加装饰性框架。
convert -mattecolor gray -frame 25x25 image.jpg image.gif
4）在图片边缘增加升、降斜角
convert -mattecolor gray -frame 25x25+0+25 image.jpg image.gif
convert -mattecolor gray -frame 25x25+25+0 image.jpg image.gif

用窗口管理器运行display失败了，怎么办? 用下列命令之一来确认display运行在一个交
互环境中：
display logo:Untitled
display < /dev/console

将PostScript文件转换为其它格式时，如何改善文字的外观？
convert -density 288 -geometry 25% image.ps image.gif

如何用2－3英寸高的文字注释一个图片? 先检查有无可缩放字体： xlsfonts -fn '*-0-0
-0-0-*'　有则：
convert -font '-*-helvetica-*-*-*--300-300-*-*-*-*-iso8859-1' \
-fill green -draw 'text 50,300 Magick' image.gif annotated.gif
# If you have the FreeType support built into ImageMagick,
# just increase your pointsize and/or density:
convert -font Helvetica -pointsize 100 -density 300 ...

如何将gif文件分析为一系列的单个图片？
convert animation.gif frame%02d.gif

用NetScape显示的图片，如何去掉周围的背景色？ convert +page alpha.gif beta.gif

如何用web安全的颜色（Web safe colors）创建GIF或PNG图片？
convert -map netscape: alpha.gif beta.gif

为何Adobe Acrobat 2.1不能读ImageMagick's制作的PDF? 用 Acrobat 3.0或以上版本，来
阅读这种经zip压缩的pdf，或制作PDF时不进行压缩。
convert +compress images.tiff image.pdf

如何在图片上增加一个不光滑层(matte channel)?
convert image.gif -matte temp.miff
composite -compose CopyOpacity mask.xbm temp.miff transparent.gif

在NT环境下如何用convert在图片上写字？
convert -font Arial -fill blue -draw "text 10,10 'your text here'" d:\test.tif
png:d:\test.png
convert.exe -pointsize 18 -draw "text 0,0 "This is my text!"" C:\blank.gif c:\
text.gif

为何GIF文件比期望的大? 需要在编译源码时加 --enable-lzw 参数，来打开LZW压缩功能
。
为何JPEG文件比期望的大? 可能嵌入Exif或IPTC等"profiles", 或者含有没压缩的thumbn
ails. 可以用命令行参数 +profile ""或相关的API来将它们去掉。
如何从图片文件中抽取第一张图片？
convert "Image.gif[0]" first.gif

如何创建一张空白图片？
convert -size 800x600 xc:"#ddddff" ltblue.ppm
convert -size 800x600 null:white white.ppm
convert in.png -threshold 100% black.ppm #<--与in.png同大小

为何GIF文件比期望的大? 需要在编译源码时加 --enable-lzw 参数，来打开LZW压缩功能
。
为何JPEG文件比期望的大? 可能嵌入Exif或IPTC等"profiles", 或者含有没压缩的thumbn
ails. 可以用命令行参数 +profile ""或相关的API来将它们去掉。

把matlab中画出的多幅图作成GIF动画
for i in `ls *.jpg`; do convert -trim -resize 350x305 $i crop.$i; done
convert -delay 10 -loop 3 crop.frame*.jpg string.gif
rm crop.frame*.jpg

生成png格式的email地址
convert -size 185x19 null:white email.png
convert -font monospace -fill black -pointsize 16 -draw 'text 4,14 "youremail@
yourdomain"' email.png email.png
convert -font monospace -fill blue -pointsize 16 -draw 'text 3,13 "youremail@y
ourdomain"' email.png email.png

# Convert all JPG images in a directory to PNG format

    mogrify -format png *.jpg

# convert image

```
for i in Screenshot_201* ; do convert $i ${i/.png/.jpg}; done

$ for i in IMG*.jpg; do width=$(identify -verbose $i | egrep Geometry|awk '{print $2}' | cut -c -4|sed 's/x//'); myname=${i##*IMG_}; if [[ $width -gt "2000" ]]; then convert -resize 50%x50% $i $myname ;echo $i, width: $width, Resized to $myname; else convert $i $myname; echo $i width: $width, No resize;fi;done

$ for i in DSC*.jpg; do width=$(identify -verbose $i | egrep Geometry|awk '{print $2}' | cut -c -4|sed 's/x//'); myname=$(identify -verbose $i|egrep exif:DateTimeOriginal|awk '{print $2"_"$3}'|sed 's+[\:\ \+]+-+g')_${i##*DSC_}; if [[ $width -gt "2000" ]]; then convert -resize 50%x50% $i $myname ;echo "$i: width $width, resized to $myname"; else convert $i $myname ; echo "$i: width $width, no resize to $myname";fi ;echo ;done
```


#!/bin/bash
chvt 7;
sleep 9;
XAUTHORITY=/var/lib/gdm/:0.Xauth DISPLAY=:0.0 import -window root /home/sp/gdm-shot.png

# Imagemagick
- http://www.imagemagick.org

# mogrify
    mogrify - resize an image, blur, crop, despeckle, dither, draw on, flip, join, re-sample, and much more. Mogrify overwrites the original image file,
    whereas, convert(1) writes to a different image file.

mogrify can also use a `-path` option to name the fold to save output files.

# convert
To resize image height with the same aspect ratio

    convert input.png -geometry x900 output.png

To scale down an image, but keeping the geometry

		convert input.jpg -resize 200x200^ output.jpg

By default, it is to crop the image from the top left corner.

To crop the image from center:

		convert input.jpg -gravity Center -crop 200x200+0+0 +repage output.jpg

To crop to start at the bottom and cut 500 pixels from the height.

		convert -gravity south -chop 0x500 *.jpg

To remove 20 rows of pixels from the bottom:

    convert image.png -gravity South -chop 0x20 result.png

Change to -gravity North to chop top 20 rows.


To resize width and height reduced proportionally:

		convert -resize 900 input.jpg output.jpg

To rotate the images 90 degress:

		convert -rotate 90 input.jpg output.jpg

To trim white borders, adds 20 pixel white borders horizontally and 10px vertically

    convert input.jpg -trim -bordercolor White -border 20x10 +repage output.jpg

		convert -resize 50% input.jpg output.jpg # resize to 50%
		convert -resize 1024x768 input.jpg output.jpg # resize, keep original aspect ratio
		convert -r 1024x768! input.jpg output.jpg # resize, enforce exact dimensions
		convert -r 1024 input.jpg output.jpgsize to width of 1024
		convert -r x768 input.jpg output.jpg # resize to height of 1024

If the source image is 1000x1000, it will not output one image, but ten of them.
    convert input.jpg -crop 100x100 output.jpg

    convert input.jpg -shave 10x10 output.jpg #shave 10px from sides

## Replacing colors and transparency
Do you need the logo in different color? Or do you need a transparent background? Both of these changes are very easy to do:

    convert white.png -fill '#000' -opaque '#fff' black.png
-fuzz can be added here to add tolerance in color replacement

If you have a jpg with white background and need to make it transparent, you can simply do:

    convert source.jpg -transparent white output.png

## Creating favicons
If the source image is at least 256x256, you can quickly convert into an ico that includes all the necessary standard image versions:

    convert source.png -define icon:auto-resize favicon.ico

    find ./ -name "*.png" -exec convert {} -trim outputfolder/{} \;

# PDF

I generate all my research graphics, charts, tables etc. using R. My semi-automated system for generating these using complex R scripts to fetch the latest data from PostgreSQL, perform analysis, and then generates PDF and Postscript files for inclusion into LaTeX documents. PDF is a great format, fully supported on the Mac, but Microsoft Word and Microsoft Powerpoint do not support PDF properly. This makes things very difficult, and while I prefer to use Apple’s Keynote program, presenting at scientific meetings tends to require Powerpoint.

Vector graphics are different to bitmap graphics, and tend to be smaller, and scale to both small and large sizes without becoming “jaggy”. Unfortunately, the standard vector file format for Microsoft applications is WMF (Windows Metafile), a proprietary and poorly documented standard, which means it is poorly supported by other operating systems, like Mac OS X and Linux. Even Microsoft’s own software on Mac OS X does not support WMF files properly, and often has difficulty importing documents using this format.

In an ideal world, Microsoft Powerpoint would support PDF graphics easily, but until it does, one needs to convert the files manually.

The best way at present appears to be to convert them to high-quality bitmap images. This involves rasterisation, and so does degrade quality, but I use a high “dots-per-inch” (DPI) when plotting, so that quality is maintained. I would recommend either 300 or 600.


convert -density 300 file.pdf file.jpg

To convert more than one file, one can use wildcards, such as *.jpg, but I prefer to use bash scripting (the default shell in Mac OS X) to batch convert files as it can preserve output filenames:


for i in `ls *.pdf`; do convert -density 300 "$i" "$i".jpg; done

And that’s it. You should end up with a directory of converted PDFs, suitable for inclusion into any Microsoft application!


convert *.png test.pdf will put your images into a single pdf.

To create a thumbnails for all pages in the PDF document (say test.pdf which has 3 pages), do

convert -thumbnail x300 test.pdf test.png
ls
> test.pdf test-0.png test-1.png test-2.png

The “x300″ tells the “convert” tool to keep the height at 300 pixels and modify the width to suit the height. If you have absolute dimensions in mind (say 400×300), do

convert -thumbnail 400x300 test.pdf test.png

If you want to control the width and have the height suited, do

convert -thumbnail 400 test.pdf test.png

What do you do if you want only the first page’s thumbnail? do,

convert -thumbnail x300 test.pdf[0] test.png

A neat feature of the “convert” tool is creation of animated gif’s having all the pages from the PDF document. do,

convert -thumbnail x300 test.pdf test.gif

“convert” is smart enough to figure out the output format from the file extension you provide in the arguments.

Nifty tools like “convert” from the ImageMagick suite are one of the reasons I love Linux!


For animated gifs you can set the delay between frames with the delay parameter (in hundredths of a second):
convert -thumbnail x300 -delay 100 test.pdf test.gif


     convert -density 400 myimage.pdf -resize 25% myimage.png
    > convert file.pdf file.png
    > convert: no decode delegate for this image format `/tmp/magick-aRiiNBVl-00000001' @ error/constitute.c/ReadImage/544.
    > convert: Postscript delegate failed `file.pdf': No such file or directory @ error/pdf.c/ReadPDFImage/678.
    > convert: no images defined `file.png' @ error/convert.c/ConvertImageCommand/3044.

It would appear that your version of IM does not have Ghostscript installed.

Please identify your version of IM and platform.

Then run the following IM command

convert -list configure

and look at the line starting with DELEGATES. What does it list? If gs or gslib is not included, then Ghostscript was either not installed or not installed successfully.


try adding -units pixelspercentimeter

my nominal computation is 72dpi*4=288 so

convert -density 288 MyImage.pdf -resize 25% MyImage.png

so try

72dpi=72/2.54=28dpc

28*4=112

convert -units pixelspercentimeter -density 112 MyImage.pdf -resize 25% MyImage.png

But you can make the density larger and get a bigger resulting png


#


 -density sets the size of the output image (in DPI, so experiment to get the required size).


This should make a white background transparent:

    convert -density 300 $FILE.pdf -transparent white $FILE.png

but it doesn't work well with anti-aliasing.

Using Ghostscript directly seems much better for transparency:

    gs -q -dNOPAUSE -dBATCH -sDEVICE=pngalpha -r300 -dEPSCrop -sOutputFile=$FILE.png $FILE.pdf


where -r sets the output size equivalently to -density above.



#  How to get ImageMagick to convert PDF to PNG with reasonable image quality

Without special effort, converting PDF to a series of PNG images produces images that look kind of corroded. The reason for this is related to ImageMagick's ghostscript backend, which sucks at antialiasing.

Thus, the only way to get better images would be to convert at an insanely high resolution (convert's density option) and resize afterwards. This can be done in one go by ImageMagick:

convert -density 1000x1000 <thepdf.pdf> -resize <xsize>x test%03d.png

However, I found that running ghostscript separately reduces the eventual image size by a factor of 2-3. I don't know why, it seems to be relatively device-independent (tested with both png16m and pngalpha).

    gs -sDEVICE=png16m -sOutputFile=test%03d.png -r1000 -dNOPAUSE -dBATCH <mypdf.pdf>

for file in test???.png; do convert $file -resize <xsize>x $file; echo $file; done


for file in *.pdf; do echo $file;convert -density 600x600 -resize 800x560 -quality 90 $file `basename $file .pdf`.png; done

# crop

    convert -crop 1150x200+30+120 input.png output.png


