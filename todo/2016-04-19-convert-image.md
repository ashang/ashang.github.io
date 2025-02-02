First
                exif:DateTimeOriginal: 2014:09:29 14:51:57
then

            exif:DateTimeDigitized: 2014:09:29 14:51:57
then
        exif:DateTime: 2014:09:29 14:51:57
Last:
    date:modify: 2014-09-30T06:49:02+00:00



$ for i in dsc*; do mv $i $(identify -verbose $i |grep exif:DateTimeDigitized: | awk '{print $2"."$3}' | sed 's+\:++g').jpg; done





    for i in *.jpg; do width=$(identify -verbose $i | egrep Geometry|awk '{print $2}' | cut -c -4|sed 's/x//'); myname=new/${i##*img_}; if [[ $width -gt "2400" ]]; then convert -resize 50%x50% $i $myname ;echo $i, width: $width, Resized to $myname; else convert $i $myname; echo $i width: $width, No resize;fi;done



