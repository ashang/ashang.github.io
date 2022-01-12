
$ make
rm -f sacd libsacd.so.19 *.o libdstdec/*.o libdsd2pcm/*.o libsacd/*.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/str_data.cpp -o libdstdec/str_data.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/ac_data.cpp -o libdstdec/ac_data.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/coded_table.cpp -o libdstdec/coded_table.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/frame_reader.cpp -o libdstdec/frame_reader.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/dst_decoder.cpp -o libdstdec/dst_decoder.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdstdec/dst_decoder_mt.cpp -o libdstdec/dst_decoder_mt.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdsd2pcm/dsd_pcm_converter_engine.cpp -o libdsd2pcm/dsd_pcm_converter_engine.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdsd2pcm/upsampler.cpp -o libdsd2pcm/upsampler.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libdsd2pcm/dsd_pcm_converter_hq.cpp -o libdsd2pcm/dsd_pcm_converter_hq.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libsacd/scarletbook.cpp -o libsacd/scarletbook.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libsacd/sacd_disc.cpp -o libsacd/sacd_disc.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libsacd/sacd_media.cpp -o libsacd/sacd_media.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libsacd/sacd_dsdiff.cpp -o libsacd/sacd_dsdiff.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c libsacd/sacd_dsf.cpp -o libsacd/sacd_dsf.o
g++  -std=c++11 -Wall -O3 -Ilibdstdec -Ilibdsd2pcm -Ilibsacd -c main.cpp -o main.o
g++  -std=c++11 -Wall -O3 -o sacd libdsd2pcm/upsampler.o libdsd2pcm/dsd_pcm_converter_hq.o libdsd2pcm/dsd_pcm_converter_engine.o libdstdec/frame_reader.o libdstdec/ac_data.o libdstdec/str_data.o libdstdec/coded_table.o libdstdec/dst_decoder.o libdstdec/dst_decoder_mt.o libsacd/sacd_media.o libsacd/sacd_dsf.o libsacd/sacd_dsdiff.o libsacd/scarletbook.o libsacd/sacd_disc.o main.o -Llibdstdec -Llibdsd2pcm -Llibsacd -lrt -lpthread

$ ./sacd -h

Usage: sacd -i infile [-o outdir] [options]

  -i, --infile         : Specify the input file (*.iso, *.dsf, *.dff)
  -o, --outdir         : The folder to write the WAVE files to. If you omit
                         this, the files will be placed in the input file's
                         directory
  -c, --stdout         : Stdout output (for pipe), sample:
                         sacd -i file.dsf -c | play -
  -r, --rate           : The output samplerate.
                         Valid rates are: 88200, 96000, 176400 and 192000.
                         If you omit this, 88.2KHz will be used.
  -s, --stereo         : Only extract the 2-channel area if it exists.
                         If you omit this, the multichannel area will have priority.
  -p, --progress       : Display progress to new lines. Use this if you intend
                         to parse the output through a script. This option only
                         lists either one progress percentage per line, or one
                         status/error message.
  -d, --details        : Show detailed information about the input
  -h, --help           : Show this help message

$ sudo apt install sox
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following additional packages will be installed:
  libopencore-amrnb0 libopencore-amrwb0 libsox-fmt-alsa libsox-fmt-base libsox3
Suggested packages:
  libsox-fmt-all
The following NEW packages will be installed:
  libopencore-amrnb0 libopencore-amrwb0 libsox-fmt-alsa libsox-fmt-base libsox3 sox
0 upgraded, 6 newly installed, 0 to remove and 2 not upgraded.
Need to get 513 kB of archives.
After this operation, 1,564 kB of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 libopencore-amrnb0 amd64 0.1.5-1 [94.8 kB]
Get:2 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 libopencore-amrwb0 amd64 0.1.5-1 [49.1 kB]
Get:3 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 libsox3 amd64 14.4.2+git20190427-2 [226 kB]
Get:4 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 libsox-fmt-alsa amd64 14.4.2+git20190427-2 [10.5 kB]
Get:5 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 libsox-fmt-base amd64 14.4.2+git20190427-2 [31.5 kB]
Get:6 http://mirrors.ustc.edu.cn/ubuntu impish/universe amd64 sox amd64 14.4.2+git20190427-2 [102 kB]
Fetched 513 kB in 0s (1,262 kB/s)
Selecting previously unselected package libopencore-amrnb0:amd64.
(Reading database ... 258838 files and directories currently installed.)
Preparing to unpack .../0-libopencore-amrnb0_0.1.5-1_amd64.deb ...
Unpacking libopencore-amrnb0:amd64 (0.1.5-1) ...
Selecting previously unselected package libopencore-amrwb0:amd64.
Preparing to unpack .../1-libopencore-amrwb0_0.1.5-1_amd64.deb ...
Unpacking libopencore-amrwb0:amd64 (0.1.5-1) ...
Selecting previously unselected package libsox3:amd64.
Preparing to unpack .../2-libsox3_14.4.2+git20190427-2_amd64.deb ...
Unpacking libsox3:amd64 (14.4.2+git20190427-2) ...
Selecting previously unselected package libsox-fmt-alsa:amd64.
Preparing to unpack .../3-libsox-fmt-alsa_14.4.2+git20190427-2_amd64.deb ...
Unpacking libsox-fmt-alsa:amd64 (14.4.2+git20190427-2) ...
Selecting previously unselected package libsox-fmt-base:amd64.
Preparing to unpack .../4-libsox-fmt-base_14.4.2+git20190427-2_amd64.deb ...
Unpacking libsox-fmt-base:amd64 (14.4.2+git20190427-2) ...
Selecting previously unselected package sox.
Preparing to unpack .../5-sox_14.4.2+git20190427-2_amd64.deb ...
Unpacking sox (14.4.2+git20190427-2) ...
Setting up libsox3:amd64 (14.4.2+git20190427-2) ...
Setting up libopencore-amrwb0:amd64 (0.1.5-1) ...
Setting up libsox-fmt-alsa:amd64 (14.4.2+git20190427-2) ...
Setting up libopencore-amrnb0:amd64 (0.1.5-1) ...
Setting up libsox-fmt-base:amd64 (14.4.2+git20190427-2) ...
Setting up sox (14.4.2+git20190427-2) ...
Processing triggers for libc-bin (2.34-0ubuntu3) ...
Processing triggers for man-db (2.9.4-2) ...
Processing triggers for mailcap (3.70) ...

$ ~/sacd/sacd -i .local/share/Trash/20211115-135054-1636955454_BEYOND.iso

sacd
----
Command-line SACD decoder
version 19.7.16

100.00%
Finished in 129 seconds.

$ file  *wav
(2ch) 01. Beyond - Peace And Love.wav:                                   RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 02. Beyond - Boundless.wav:                                        RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 03. Beyond - Lovers.wav:                                           RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 04. Beyond - The Wall.wav:                                         RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 05. Beyond - .wav:                                                 RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 06. Beyond - The Early Train.wav:                                  RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 07. Beyond - Pa Pa & Ma Ma.wav:                                    RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 08. Beyond - .wav:                                                 RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 09. Beyond - Why.wav:                                              RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 10. Beyond - Watching.wav:                                         RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 11. Beyond - .wav:                                                 RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 12. Beyond - .wav:                                                 RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 13. Beyond - Neverending Lonely.wav:                               RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 14. Beyond - I Am Angry.wav:                                       RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 15. Beyond - Fate Is My Home.wav:                                  RIFF (little-endian) data, WAVE audio, stereo 88200 Hz
(2ch) 16. Beyond - .wav:                                                 RIFF (little-endian) data, WAVE audio, stereo 88200 Hz

$ mpv *2ch*wav
Playing: (2ch) 01. Beyond - Peace And Love.wav
 (+) Audio --aid=1 (pcm_s24le 2ch 88200Hz)
AO: [pulse] 88200Hz stereo 2ch s32

A: 00:03:25 / 00:03:26 (100%)

Playing: (2ch) 02. Beyond - Boundless.wav
 (+) Audio --aid=1 (pcm_s24le 2ch 88200Hz)
A: 00:05:21 / 00:05:22 (100%)

Playing: (2ch) 03. Beyond - Lovers.wav
 (+) Audio --aid=1 (pcm_s24le 2ch 88200Hz)


$ ~/sacd/sacd -i DANCES_WITH_WOLVES___ORIGINAL_MOTION_PICTURE_SOUNDTRACK.iso 

sacd
----
Command-line SACD decoder
version 19.7.16

100.00%
Finished in 63 seconds.

# ps3dev
export PS3DEV=/opt/ps3dev
export PATH=$PATH:$PS3DEV/bin
export PATH=$PATH:$PS3DEV/ppu/bin
export PATH=$PATH:$PS3DEV/spu/bin
export PSL1GHT=$PS3DEV/psl1ght
export PATH=$PATH:$PSL1GHT/host/bin

