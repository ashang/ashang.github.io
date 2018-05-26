---
author: aaronshang
comments: true
date: 2010-10-29 10:30:38+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/29/target-directory/
slug: target-directory
title: target-directory
wordpress_id: 41
tags:
- coreutils
- target-directory
---

man ln

       -t, --target-directory=DIRECTORY
              specify the DIRECTORY in which to create the links

e.g.:

ln -s file1 file2 dirX

ln -s file1 file2 dirX -t dirY



$ info coreutils 'Target directory'
