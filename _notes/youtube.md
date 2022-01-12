---
title: youtube
date: 2019-04-10
---

```
$ youtube-dl --write-auto-sub --skip-download https://www....=alMHLEzvEAI -o '%(id)s.%(ext)s'
$ youtube-dl --write-auto-sub --skip-download alMHLEzvEAI -o '%(id)s.%(ext)s'
```

saves the subtitles from YouTube to alMHLEzvEAI.en.vtt, yes that's the video ID

```
$ grep -v '[<>]' < alMHLEzvEAI.en.vtt | grep [a-z] | uniq > plain.txt
```

strips out the timestamps and scrolling repetitions. Of course it's an un-punctuated semi-solid wall of text, but it's free.

## youtube web player debug

```json
{
  "ns": "yt",
  "el": "embedded",
  "cpn": "20jRS_LPCHQMoaKm",
  "ver": 2,
  "cmt": "174.808",
  "fmt": "247",
  "fs": "0",
  "rt": "108.411",
  "euri": "https://www.byobu.org/",
  "lact": 24,
  "cl": "419703423",
  "mos": 0,
  "state": "8",
  "volume": 40,
  "cbr": "Chrome",
  "cbrver": "96.0.4664.93",
  "c": "WEB_EMBEDDED_PLAYER",
  "cver": "1.20220104.01.00",
  "cplayer": "UNIPLAYER",
  "cos": "X11",
  "cplatform": "DESKTOP",
  "autoplay": "1",
  "hl": "en_US",
  "cr": "NO",
  "len": "644.861",
  "fexp": "23748147,23858057,23983296,24001373,24002022,24002025,24002922,24004644,24007246,24080738,24082661,24106565,24129402,24141079,24146886",
  "afmt": "251",
  "size": "1154:632",
  "inview": "0",
  "muted": "0",
  "docid": "NawuGmcvKus",
  "ei": "Pj7dYZ7HEM-SyQWfyYfQBQ",
  "plid": "AAXVSicCaku4k0r0",
  "referrer": "https://www.youtube.com/embed/NawuGmcvKus",
  "of": "0cwX5iRDTWO9nGUCohdy7w",
  "vm": "CAQQARgBOjJBS1JhaHdCSUhTaGVqd1R1MjJtZFNPbElyUnQwcHVtSHNxMndtSWV0bjR6bXgwMW96QWJXQVBta0tESWxicXdxMnZVSnJtNDdUYkxYeGpYVHdteHp1WV8wNVV3d3FYd1Fma01fUVYtMG5ITkhLNndPMnFEa21ibERhdl94WW1EMWQxb3BiX2EzWU9r",
  "vct": "174.808",
  "vd": "644.861",
  "vpl": "74.912-174.808",
  "vbu": "74.667-208.000",
  "vpa": "0",
  "vsk": "0",
  "ven": "0",
  "vpr": "1",
  "vrs": "4",
  "vns": "2",
  "vec": "null",
  "vemsg": "",
  "vvol": "0.4",
  "vdom": "1",
  "vsrc": "1",
  "vw": "1117",
  "vh": "632",
  "lct": "174.561",
  "lsk": false,
  "lmf": false,
  "lbw": "345653.299",
  "lhd": "1.065",
  "lst": "4708.051",
  "laa": "itag_251_type_3_seg_20_range_3463334-3634582_time_200.0-210.0_off_0_len_171249_end_1",
  "lva": "itag_247_type_3_seg_38_range_8487696-8674908_time_202.7-208.0_off_0_len_187213_end_1",
  "lar": "itag_251_type_3_seg_20_range_3463334-3634582_time_200.0-210.0_off_0_len_171249_end_1",
  "lvr": "itag_247_type_3_seg_48_range_10442797-10682442_time_256.0-261.3_off_0_len_239646_end_1",
  "laq": "0",
  "lvq": "2007534",
  "lab": "70.001-210.001",
  "lvb": "74.667-208.000",
  "ismb": 920000,
  "relative_loudness": "-9.153",
  "optimal_format": "720p",
  "user_qual": 0,
  "release_version": "youtube.player.web_20220104_01_RC00",
  "debug_videoId": "NawuGmcvKus",
  "0sz": "false",
  "op": "",
  "yof": "false",
  "dis": "",
  "gpu": "ANGLE_(Intel,_Mesa_Intel(R)_UHD_Graphics_620_(WHL_GT2),_OpenGL_4.6_(Core_Profile)_Mesa_21.3.3)",
  "debug_playbackQuality": "hd720",
  "debug_date": "Tue Jan 11 2022 16:24:10 GMT+0800 (Hong Kong Standard Time)"
}
```
