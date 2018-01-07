---
author: aaronshang
comments: true
date: 2010-10-29 10:24:06+00:00
excerpt: grep utf-8 contents
layout: post
link: https://aaronshang.wordpress.com/2010/10/29/grep-utf-8-contents/
slug: grep-utf-8-contents
title: grep utf-8 contents
wordpress_id: 38
tags:
- grep
- utf-8
---

grep utf-8 contents

If your locale is some utf-8, then just grep.

If not utf-8 locale, then make a change:





<blockquote>$ iconv -f utf-8 -t your_current_locale < your_utf-8_target_file -o new_file_as_your_locale</blockquote>
